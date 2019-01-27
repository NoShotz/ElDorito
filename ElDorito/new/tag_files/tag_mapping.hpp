#pragma once
#include <cseries\cseries.hpp>
#include <tag_files\tag_groups.hpp>

namespace blam
{
	enum tag_mapping_variable_type : char_enum
	{
		_tag_mapping_variable_type_emitter_age = 0x0,
		_tag_mapping_variable_type_particle_random = 0x1,
		_tag_mapping_variable_type_emitter_random = 0x2,
		_tag_mapping_variable_type_particle_random1 = 0x3,
		_tag_mapping_variable_type_particle_random2 = 0x4,
		_tag_mapping_variable_type_particle_random3 = 0x5,
		_tag_mapping_variable_type_particle_random4 = 0x6,
		_tag_mapping_variable_type_emitter_random1 = 0x7,
		_tag_mapping_variable_type_emitter_random2 = 0x8,
		_tag_mapping_variable_type_emitter_time = 0x9,
		_tag_mapping_variable_type_system_lod = 0xA,
		_tag_mapping_variable_type_game_time = 0xB,
		_tag_mapping_variable_type_effect_a_scale = 0xC,
		_tag_mapping_variable_type_effect_b_scale = 0xD,
		_tag_mapping_variable_type_physics_rotation = 0xE,
		_tag_mapping_variable_type_location_random = 0xF,
		_tag_mapping_variable_type_distance_from_emitter = 0x10,
		_tag_mapping_variable_type_particle_simulation_a = 0x11,
		_tag_mapping_variable_type_particle_simulation_b = 0x12,
		_tag_mapping_variable_type_particle_velocity = 0x13,
		_tag_mapping_variable_type_invalid = 0x14
	};
	static_assert(sizeof(tag_mapping_variable_type) == 0x1);
	
	enum tag_mapping_output_modifier : char_enum
	{
		_tag_mapping_output_modifier_none = 0x0,
		_tag_mapping_output_modifier_plus = 0x1,
		_tag_mapping_output_modifier_times = 0x2,
		_tag_mapping_output_modifier_unknown = 0x3
	};
	static_assert(sizeof(tag_mapping_output_modifier) == 0x1);

	enum tag_mapping_flags : byte_flags
	{
		_tag_mapping_flags_none = 0x0,
		_tag_mapping_flags_force_constant = 0x1,
	};
	static_assert(sizeof(tag_mapping_flags) == 0x1);

	struct tag_mapping
	{
		tag_mapping_variable_type input_variable;
		tag_mapping_variable_type range_variable;
		tag_mapping_output_modifier output_modifier;
		tag_mapping_variable_type output_modifier_input;
		tag_data function;
		dword runtime_m_constant_value;
		byte_flags runtime_m_flags;
		char : 8;
		char : 8;
		char : 8;
	};
	static_assert(sizeof(tag_mapping) == 0x20);
}