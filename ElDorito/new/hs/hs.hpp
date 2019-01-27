#pragma once

#include <cseries\cseries.hpp>
#include <memory\data.hpp>

namespace blam
{
	enum hs_type : unsigned short
	{
		_hs_invalid = 0xBABA,
		_hs_unparsed = 0,
		_hs_special_form,
		_hs_function_name,
		_hs_passthrough,
		_hs_type_void,
		_hs_type_boolean,
		_hs_type_real,
		_hs_type_short,
		_hs_type_long,
		_hs_type_string,
		_hs_type_script,
		_hs_type_string_id,
		_hs_type_unit_seat_mapping,
		_hs_type_trigger_volume,
		_hs_type_cutscene_flag,
		_hs_type_cutscene_camera_point,
		_hs_type_cutscene_title,
		_hs_type_cutscene_recording,
		_hs_type_device_group,
		_hs_type_ai,
		_hs_type_ai_command_list,
		_hs_type_ai_command_script,
		_hs_type_ai_behavior,
		_hs_type_ai_orders,
		_hs_type_ai_line,
		_hs_type_starting_profile,
		_hs_type_conversation,
		_hs_type_zone_set,
		_hs_type_designer_zone,
		_hs_type_point_reference,
		_hs_type_style,
		_hs_type_object_list,
		_hs_type_folder,
		_hs_type_sound,
		_hs_type_effect,
		_hs_type_damage,
		_hs_type_looping_sound,
		_hs_type_animation_graph,
		_hs_type_damage_effect,
		_hs_type_object_definition,
		_hs_type_bitmap,
		_hs_type_shader,
		_hs_type_render_model,
		_hs_type_structure_definition,
		_hs_type_lightmap_definition,
		_hs_type_cinematic_definition,
		_hs_type_cinematic_scene_definition,
		_hs_type_bink_definition,
		_hs_type_any_tag,
		_hs_type_any_tag_not_resolving,
		_hs_type_game_difficulty,
		_hs_type_team,
		_hs_type_mp_team,
		_hs_type_controller,
		_hs_type_button_preset,
		_hs_type_joystick_preset,
		_hs_type_player_character_type,
		_hs_type_voice_output_setting,
		_hs_type_voice_mask,
		_hs_type_subtitle_setting,
		_hs_type_actor_type,
		_hs_type_model_state,
		_hs_type_event,
		_hs_type_character_physics,
		_hs_type_primary_skull,
		_hs_type_secondary_skull,
		_hs_type_object,
		_hs_type_unit,
		_hs_type_vehicle,
		_hs_type_weapon,
		_hs_type_device,
		_hs_type_scenery,
		_hs_type_effect_scenery,
		_hs_type_object_name,
		_hs_type_unit_name,
		_hs_type_vehicle_name,
		_hs_type_weapon_name,
		_hs_type_device_name,
		_hs_type_scenery_name,
		_hs_type_effect_scenery_name,
		_hs_type_cinematic_lightprobe,
		_hs_type_animation_budget_reference,
		_hs_type_looping_sound_budget_reference,
		_hs_type_sound_budget_reference,
		
		k_number_of_hs_types
	};
	static_assert(sizeof(hs_type) == 0x2);

	enum hs_script_type
	{
		_hs_script_type_startup,
		_hs_script_type_dormant,
		_hs_script_type_continuous,
		_hs_script_type_static,
		_hs_script_type_command_script,
		_hs_script_type_stub,

		k_number_of_hs_script_types
	};

	struct hs_function_definition
	{
		hs_type return_type;
		word_flags flags; // unused
		void(*evaluate)(long function_index, datum_index expression_index, bool execute);
		const char *parameter_info;
		short parameter_count;
#pragma warning(push)
#pragma warning(disable : 4200)
		hs_type parameter_types[];
#pragma warning(pop)
	};
	static_assert(sizeof(hs_function_definition) == 0x10);

	void hs_dump_functions();
}