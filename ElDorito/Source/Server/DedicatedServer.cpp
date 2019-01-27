#include <WS2tcpip.h>
#include "DedicatedServer.hpp"
#include "../Modules/ModuleBase.hpp"
#include "../Blam/BlamNetwork.hpp"

namespace Server::DedicatedServer
{
	bool needToSetMode = false;

	void Init()
	{
		Blam::Network::SetLobbyType(Blam::eLobbyTypeMultiplayer);
		needToSetMode = true;
	}
	void Tick()
	{
		if (!needToSetMode) {
			if (Blam::Network::GetLobbyType() != Blam::eLobbyTypeMultiplayer) {
				Blam::Network::SetLobbyType(Blam::eLobbyTypeMultiplayer);
				needToSetMode = true;
			}
			return;
		}

		if (Blam::Network::GetLobbyType() == Blam::eLobbyTypeMultiplayer) {
			if (Blam::Network::SetNetworkMode(Blam::eNetworkModeSystemLink)) {
				needToSetMode = false;
			}
		}
	}
}