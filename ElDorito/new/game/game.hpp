#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace blam
{
	//
	// TODO: Move these to more appropriate places?
	//

	inline bool game_in_progress() { return ((bool(*)())0x5314B0)(); }

	inline BOOL game_is_campaign() { return ((BOOL(*)())0x531A60)(); }

	inline bool game_is_cooperative() { return ((bool(*)())0x531A80)(); }

	inline bool game_is_multiplayer() { return ((bool(*)())0x531C00)(); }

	inline bool game_is_survival() { return ((bool(*)())0x531E20)(); }

	inline bool game_is_mainmenu() { return ((bool(*)())0x531E90)(); }

	inline bool __cdecl game_is_team_game() { return ((bool(__cdecl *)())0x5565E0)(); }

	inline bool game_is_map_loading() { return ((bool(*)())0x5670E0)(); }

	inline void *game_get_current_engine() { return ((void *(*)())0x5CE150)(); }
}