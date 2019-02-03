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

	enum player_action : long
	{
		_player_action_test_action = 0x0,
		_player_action_test_jump = 0x1,
		_player_action_test_accept = 0x2,
		_player_action_test_cancel = 0x3,
		_player_action_test_primary_trigger = 0x4,
		_player_action_test_grenade_trigger = 0x5,
		_player_action_test_melee = 0x6,
		_player_action_test_rotate_weapons = 0x7,
		_player_action_test_rotate_grenades = 0x8,
		_player_action_test_zoom = 0x9,
		_player_action_test_look_relative_up = 0xA,
		_player_action_test_look_relative_down = 0xB,
		_player_action_test_look_relative_left = 0xC,
		_player_action_test_look_relative_right = 0xD,
		_player_action_test_unkown_0x0E = 0xE,
		_player_action_test_unkown_0x0F = 0xF,
		_player_action_test_unkown_0x10 = 0x10,
		_player_action_test_unkown_0x11 = 0x11,
		_player_action_test_back = 0x12,
		_player_action_test_unkown_0x13 = 0x13,
		_player_action_test_lookstick_forward = 0x14,
		_player_action_test_lookstick_backward = 0x15,
		_player_action_test_dpad_left = 0x16,
		_player_action_test_dpad_right = 0x17,
		_player_action_test_dpad_up = 0x18,
		_player_action_test_dpad_down = 0x19,
		_player_action_test_look_invert = 0x1A,
		_player_action_test_x = 0x1B,
		_player_action_test_y = 0x1C,
		_player_action_test_left_shoulder = 0x1D,
		_player_action_test_right_shoulder = 0x1E,
		_player_action_test_unkown_0x1F = 0x1F,
		_player_action_test_unkown_0x20 = 0x20,
	};
	static_assert(sizeof(player_action) == 0x4);
}