#include "PostgameController.hpp"
#include <ctime>
#include "../Patches/Network.hpp"
#include "../Modules/ModuleServer.hpp"
#include "../Utils/Logger.hpp"

namespace
{
	void OnLifeCycleStateChanged(Blam::LifeCycleState newState);

	time_t writeStatsStartTime;
	bool returningToLobby = false;
}

namespace Server::PostgameController
{
	void Init()
	{
		Patches::Network::OnLifeCycleStateChanged(OnLifeCycleStateChanged);
	}

	void Tick()
	{
		auto session = Blam::Network::GetActiveSession();
		if (session->IsEstablished() && session->IsHost())
		{
			auto returnToLobbyTimeout = Modules::ModuleServer::Instance().VarReturnToLobbyTimeoutSeconds->ValueInt;
			if (returningToLobby)
			{
				if (session->Parameters.GetSessionMode() == 1)
				{
					returningToLobby = false;
				}
				else
				{
					time_t now;
					time(&now);
					auto deltaTime = (now - writeStatsStartTime);
					if (deltaTime > returnToLobbyTimeout)
					{
						Utils::Logger::Instance().Log(Utils::LogTypes::Network, Utils::LogLevel::Warning, "The server failed to return to the lobby after %d seconds. Forcing back", deltaTime);
						session->Parameters.SetSessionMode(1);
					}
				}
			}
		}
	}
}

namespace
{
	void OnLifeCycleStateChanged(Blam::LifeCycleState newState)
	{
		switch (newState)
		{
		case Blam::LifeCycleState::eLifeCycleStateEndGameWriteStats:
			time(&writeStatsStartTime);
			returningToLobby = true;
			break;
		}
	}
}
