#pragma once

#include <string>

namespace Server::ReportHandler
{
	void Init();
	void Tick();
	void Handle(const std::string &token);
}