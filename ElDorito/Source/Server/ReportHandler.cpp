#include "ReportHandler.hpp"
#include <string>
#include <Windows.h>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "../Utils/Logger.hpp"
#include "../Patches/Core.hpp"
#include "../ThirdParty/HttpRequest.hpp"
#include "../Utils/String.hpp"
#include "../Utils/VersionInfo.hpp"
#include <fstream>
#include "../ThirdParty/rapidjson/document.h"
#include "../ThirdParty/rapidjson/error/en.h"

namespace
{
	const auto kReportHandlerGriefTimeSeconds = 60;

	DWORD WINAPI HandledReportsThreadProc(LPVOID lpParam);
	void OnShutdown();

	struct ReportRequest
	{
		time_t CreationTime;
		std::string Token;
	};

	std::vector<ReportRequest> pending;
	std::mutex mutex;
	std::condition_variable signal;

	std::vector<std::string> playerReportUrls;

	bool shouldExit = false;
}

namespace Server::ReportHandler
{
	void Handle(const std::string &token)
	{
		{
			std::lock_guard<std::mutex> guard(mutex);

			ReportRequest request;
			time(&request.CreationTime);
			request.Token = token;

			pending.emplace_back(request);
		}
		signal.notify_one();
	}

	void Tick()
	{

	}

	void Init()
	{
		Patches::Core::OnShutdown(OnShutdown);
		CreateThread(nullptr, 0, HandledReportsThreadProc, nullptr, 0, nullptr);
	}
}

namespace
{
	// retrieves player report endpoints from dewrito.json
	void GetEndpoints()
	{
		const auto dewritoJsonPath = "mods/dewrito.json";

		std::ifstream in(dewritoJsonPath, std::ios::in | std::ios::binary);
		if (!in || !in.is_open())
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::GetEndpoints(): Failed to open \"%s\". LastError: %d", dewritoJsonPath, GetLastError());
			return;
		}

		std::stringstream ss;
		ss << in.rdbuf();

		rapidjson::Document json;
		if (json.Parse<0>(ss.str().c_str()).HasParseError())
		{
			auto error = rapidjson::GetParseError_En(json.GetParseError());
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::GetEndpoints(): Failed to parse \"%s\": %s", dewritoJsonPath, error);
			return;
		}

		if (json.IsObject() && json.HasMember("playerReportUrls"))
		{
			playerReportUrls.clear();
			auto& urls = json["playerReportUrls"];
			for (rapidjson::SizeType i = 0; i < urls.Size(); i++)
				playerReportUrls.push_back(urls[i].GetString());
		}
	}

	bool ForwardReportToEndpoint(const std::string &endpoint, const std::string &report)
	{
		HttpRequest req(L"ElDewrito/" + Utils::String::WidenString(Utils::Version::GetVersionString()), L"", L"");

		try
		{
			if (!req.SendRequest(Utils::String::WidenString(endpoint), L"POST", L"", L"", L"", (void*)report.c_str(), report.size()))
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::ForwardReportToEndpoint(): Unable to forward player report to \"%s\". LastError: %d", endpoint.c_str(), req.lastError);
				return false;
			}
		}
		catch (...) // TODO: find out what exception is being caused
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::ForwardReportToEndpoint(): Exception while forwarding report player to \"%s\"", endpoint.c_str());
			return false;
		}

		// make sure the server replied with 200 OK
		std::wstring expected = L"HTTP/1.1 200 OK";
		if (req.responseHeader.length() < expected.length())
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::ForwardReportToEndpoint(): Invalid server query response from \"%s\". LastError %d", endpoint.c_str(), req.lastError);
			return false;
		}

		auto statusCode = req.responseHeader.substr(0, expected.length());
		if (statusCode != expected)
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler::ForwardReportToEndpoint(): Server returned response status code: %d", statusCode);
			return false;
		}

		std::string resp = std::string(req.responseBody.begin(), req.responseBody.end());

		std::ofstream logfile("player_reports.log", std::ios::app);
		logfile << resp << "\n\n";
		logfile.flush();

		return true;
	}

	void ForwardReportToEndpoints(const std::string &report)
	{
		for (auto &endpoint : playerReportUrls)
			ForwardReportToEndpoint(endpoint, report);
	}


	bool HandleReport(const std::string &token)
	{
		HttpRequest req(L"ElDewrito/" + Utils::String::WidenString(Utils::Version::GetVersionString()), L"", L"");

		try
		{
			if (!req.SendRequest(L"http://halostats.click/api/verifyreport?t=" + Utils::String::WidenString(token), L"GET", L"", L"", L"", NULL, 0))
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler Unable to connect to report verification endpoint. LastError: %d", req.lastError);
			}
		}
		catch (...) // TODO: find out what exception is being caused
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler Exception while verifying player report token");
			return false;
		}

		// make sure the server replied with 200 OK
		std::wstring expected = L"HTTP/1.1 200 OK";
		if (req.responseHeader.length() < expected.length())
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler: Invalid server query response. LastError %d", req.lastError);
			return false;
		}

		auto statusCode = req.responseHeader.substr(0, expected.length());
		if (statusCode != expected)
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler: Server returned response status code: %s", statusCode.c_str());
			return false;
		}

		std::string resp = std::string(req.responseBody.begin(), req.responseBody.end());

		std::ofstream logfile("player_reports.log", std::ios::app);
		logfile << resp << "\n\n";
		logfile.flush();

		ForwardReportToEndpoints(resp);

		return true;
	}

	void HandleReports()
	{
		if (!pending.size())
			return;

		GetEndpoints();
		for (auto it = pending.begin(); it != pending.end();)
		{
			auto &request = *it;

			auto deltaTime = (time(nullptr) - request.CreationTime);

			if (HandleReport(request.Token))
			{
				it = pending.erase(it);
			}
			else if (deltaTime > kReportHandlerGriefTimeSeconds)
			{
				it = pending.erase(it);
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::ReportHandler: Failed to handle report after %d seconds", kReportHandlerGriefTimeSeconds);
			}
			else
			{
				it++;
			}
		}
	}

	DWORD WINAPI HandledReportsThreadProc(LPVOID lpParam)
	{
		for (;;)
		{
			std::unique_lock<std::mutex> lk(mutex);
			auto now = std::chrono::system_clock::now();
			signal.wait_for(lk, std::chrono::seconds(5));

			if (shouldExit)
				return 0;

			HandleReports();
		}

		return 0;
	}

	void OnShutdown()
	{
		shouldExit = true;
		signal.notify_one();
	}
}
