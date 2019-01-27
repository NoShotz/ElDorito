#include "BanListSync.hpp"
#include "BanList.hpp"
#include <Windows.h>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <fstream>
#include "../ThirdParty/rapidjson/error/en.h"
#include "../ThirdParty/rapidjson/writer.h"
#include "../ThirdParty/rapidjson/stringbuffer.h"
#include "../ThirdParty/rapidjson/document.h"
#include "../ThirdParty/HttpRequest.hpp"
#include "../Utils/Logger.hpp"
#include "../Blam/BlamNetwork.hpp"
#include "../Patches/Core.hpp"
#include "../Modules/ModuleServer.hpp"

namespace
{
	DWORD WINAPI BanListSyncThreadProc(LPVOID lpParam);
	void OnShutdown();
	void CheckToBootPlayers();

	time_t lastSyncTime;
	std::mutex mutex;
	std::condition_variable syncSignal;
	bool shouldExit = false;
	bool banlistDirty = false;

	struct
	{
		std::vector<std::string> Subnets;
		std::vector<std::string> Names;
		std::vector<std::string> Uids;
		std::vector<std::string> Ips;
	} 
	sharedState;
	std::vector<std::string> banlistUrls;
}

namespace Server::BanListSync
{
	void Init()
	{
		CreateThread(nullptr, 0, BanListSyncThreadProc, nullptr, 0, nullptr);
		Patches::Core::OnShutdown(OnShutdown);
	}

	void Tick()
	{
		auto* session = Blam::Network::GetActiveSession();
		if (!session || !session->IsEstablished() || !session->IsHost())
			return;

		if (banlistDirty)
		{
			std::unique_lock<std::mutex> lock(mutex, std::try_to_lock);
			if (lock.owns_lock())
			{
				banlistDirty = false;

				auto &halostatsBanList = Server::HalostatsBanList::Instance();
				halostatsBanList.ClearList();

				for (const auto &ip : sharedState.Ips)
					Server::HalostatsBanList::Instance().AddIp(ip);
				for (const auto &uid : sharedState.Uids)
					Server::HalostatsBanList::Instance().AddUID(uid);
				for (const auto &name : sharedState.Names)
					Server::HalostatsBanList::Instance().AddName(name);
				for (const auto &subnet : sharedState.Subnets)
					Server::HalostatsBanList::Instance().AddSubnet(subnet);

				CheckToBootPlayers();
			}
		}

		auto syncInternval = Modules::ModuleServer::Instance().VarBanListSyncIntervalSeconds->ValueInt;

		time_t now;
		time(&now);
		if((now- lastSyncTime) > syncInternval)
		{
			lastSyncTime = now;
			syncSignal.notify_one();
		}
	}
}

namespace
{
	// retrieves player report endpoints from dewrito.json
	bool GetEndpoints()
	{
		const auto dewritoJsonPath = "mods/dewrito.json";

		std::ifstream in(dewritoJsonPath, std::ios::in | std::ios::binary);
		if (!in || !in.is_open())
		{
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::BanListSync::GetEndpoints(): Failed to open \"%s\". LastError: %d", dewritoJsonPath, GetLastError());
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();

		rapidjson::Document json;
		if (json.Parse<0>(ss.str().c_str()).HasParseError())
		{
			auto error = rapidjson::GetParseError_En(json.GetParseError());
			Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::BanListSync::GetEndpoints(): Failed to parse \"%s\": %s", dewritoJsonPath, error);
			return false;
		}

		if (json.IsObject() && json.HasMember("banlistUrls"))
		{
			banlistUrls.clear();
			auto& urls = json["banlistUrls"];
			if (!urls.IsArray())
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Error, "Server::BanListSync::GetEndpoints(): \"banlistUrls\" must be an array \"%s\"", dewritoJsonPath);
				return false;
			}			

			for (rapidjson::SizeType i = 0; i < urls.Size(); i++)
				banlistUrls.push_back(urls[i].GetString());
		}

		return true;
	}


	void CheckToBootPlayers()
	{
		auto* session = Blam::Network::GetActiveSession();
		if (!session || !session->IsEstablished() || !session->IsHost())
			return;

		auto &halostatsBanList = Server::HalostatsBanList::Instance();
		int peerIdx = session->MembershipInfo.FindFirstPeer();
		while (peerIdx != -1)
		{
			int playerIdx = session->MembershipInfo.GetPeerPlayer(peerIdx);
			if (playerIdx != -1)
			{
				auto* player = &session->MembershipInfo.PlayerSessions[playerIdx];
				std::string name = Utils::String::ThinString(player->Properties.DisplayName);
				uint64_t uid = player->Properties.Uid;

				std::stringstream stream;
				stream << std::hex << uid;
				std::string hexUID = stream.str();

				const std::string &ipString = session->GetPeerAddress(peerIdx).ToString();

				if (Server::HalostatsBanList::Instance().ContainsIp(ipString))
				{
					if (!Blam::Network::BootPlayer(playerIdx, 4))
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Failed to Kick Banned IP: " + ipString);
					else
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Successfully Kicked Banned IP: " + ipString);
				}

				if (Server::HalostatsBanList::Instance().ContainsUID(hexUID))
				{
					if (!Blam::Network::BootPlayer(playerIdx, 4))
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Failed to Kick Banned UID: " + hexUID);
					else
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Successfully Kicked Banned UID: " + hexUID);
				}

				if (Server::HalostatsBanList::Instance().ContainsName(name))
				{
					if (!Blam::Network::BootPlayer(playerIdx, 4))
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Failed to Kick Banned Name: " + name);
					else
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Successfully Kicked Banned Name: " + name);
				}
			}
			peerIdx = session->MembershipInfo.FindNextPeer(peerIdx);
		}
	}

	bool SyncBanList()
	{
		if (!GetEndpoints())
			return false;

		sharedState.Ips.clear();
		sharedState.Subnets.clear();
		sharedState.Names.clear();
		sharedState.Uids.clear();

		for (auto &endpoint : banlistUrls)
		{
			HttpRequest req(L"ElDewrito/" + Utils::String::WidenString(Utils::Version::GetVersionString()), L"", L"");

			if (!req.SendRequest(Utils::String::WidenString(endpoint), L"GET", L"", L"", L"", NULL, 0))
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Unable to connect to banlist endpoint. \"%s\"", endpoint.c_str());
				continue;
			}
			// make sure the server replied with 200 OK
			std::wstring expected = L"HTTP/1.1 200 OK";
			if (req.responseHeader.length() < expected.length())
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Invalid server query response. \"%s\"", endpoint.c_str());
				continue;
			}

			// parse the json response
			std::string resp = std::string(req.responseBody.begin(), req.responseBody.end());
			rapidjson::Document json;
			if (json.Parse<0>(resp.c_str()).HasParseError() || !json.IsObject())
			{
				Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Info, "Invalid json returned from banlist endpoint. \"%s\"", endpoint.c_str());
				continue;
			}

			if (json.HasMember("ips"))
			{
				const rapidjson::Value& IPs = json["ips"];
				for (rapidjson::SizeType i = 0; i < IPs.Size(); i++)
					sharedState.Ips.push_back(IPs[i].GetString());
			}
			if (json.HasMember("uids"))
			{
				const rapidjson::Value& UIDs = json["uids"];
				for (rapidjson::SizeType i = 0; i < UIDs.Size(); i++)
					sharedState.Uids.push_back(UIDs[i].GetString());
			}
			if (json.HasMember("names"))
			{
				const rapidjson::Value& Names = json["names"];
				for (rapidjson::SizeType i = 0; i < Names.Size(); i++)
					sharedState.Names.emplace_back(Names[i].GetString());
			}
			if (json.HasMember("subnets"))
			{
				const rapidjson::Value& Subnets = json["subnets"];
				for (rapidjson::SizeType i = 0; i < Subnets.Size(); i++)
					sharedState.Subnets.emplace_back(Subnets[i].GetString());
			}
		}

		return true;
	}

	DWORD WINAPI BanListSyncThreadProc(LPVOID lpParam)
	{
		for (;;)
		{
			std::unique_lock<std::mutex> lk(mutex);
			syncSignal.wait(lk);

			if (shouldExit)
				return 0;

			if (SyncBanList())
				banlistDirty = true;
		}
	}

	void OnShutdown()
	{
		shouldExit = true;
		syncSignal.notify_one();
	}
}
