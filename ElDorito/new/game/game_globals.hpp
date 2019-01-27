#pragma once
#include <cseries\cseries.hpp>
#include <game\game_mode.hpp>

namespace blam
{
	struct game_globals
	{
		char unknown0[0x10];
		game_mode current_game_mode;
		char unknown14[0x13A];
		short current_insertion_point;
		char unknown150[0x250B8];
	};
	static_assert(sizeof(game_globals) == 0x25208);

	game_globals *__cdecl game_globals_get();
}