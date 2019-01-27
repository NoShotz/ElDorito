#pragma once

namespace blam
{
	enum class game_mode : long
	{
		none,
		campaign,
		multiplayer,
		mainmenu,
		shared
	};
	static_assert(sizeof(game_mode) == 0x4);
}