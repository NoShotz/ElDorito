#pragma once

#include <cseries\cseries.hpp>
#include <cseries\integer_math.hpp>

namespace blam
{
	enum player_color_type : long
	{
		_player_color_primary,
		_player_color_secondary,
		_player_color_visor,
		_player_color_lights,

		k_number_of_player_color_types
	};
	static_assert(sizeof(player_color_type) == 0x4);

	enum player_armor_piece : long
	{
		_player_armor_helmet,
		_player_armor_chest,
		_player_armor_right_shoulder,
		_player_armor_left_shoulder,

		k_number_of_player_armor_pieces
	};
	static_assert(sizeof(player_armor_piece) == 0x4);

	struct player_customization_data
	{
		argb_color colors[k_number_of_player_color_types];
		long : 32;
		byte armor_pieces[k_number_of_player_armor_pieces];
		char : 8;
		char : 8;
		char : 8;
		long : 32;
	};
	static_assert(sizeof(player_customization_data) == 0x20);


}