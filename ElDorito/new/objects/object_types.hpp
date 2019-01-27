#pragma once

#include <cseries\cseries.hpp>
#include <memory\data.hpp>
#include <tag_files\tag_definitions.hpp>

#include "object_data.hpp"

namespace blam
{
	enum
	{
		_object_type_none = -1,

		_object_type_biped,
		_object_type_vehicle,
		_object_type_weapon,
		_object_type_equipment,
		_object_type_arg_device,
		_object_type_terminal,
		_object_type_projectile,
		_object_type_scenery,
		_object_type_machine,
		_object_type_control,
		_object_type_sound_scenery,
		_object_type_crate,
		_object_type_creature,
		_object_type_giant,
		_object_type_effect_scenery,

		_object_type_mask_device =
			(1 << _object_type_arg_device) |
			(1 << _object_type_terminal) |
			(1 << _object_type_machine) |
			(1 << _object_type_control),

		_object_type_mask_item =
			(1 << _object_type_weapon) |
			(1 << _object_type_equipment),

		_object_type_mask_motor =
			(1 << _object_type_biped) |
			(1 << _object_type_vehicle) |
			(1 << _object_type_creature) |
			(1 << _object_type_giant),

		_object_type_mask_unit =
			(1 << _object_type_biped) |
			(1 << _object_type_vehicle) |
			(1 << _object_type_giant),

		_object_type_mask_all =
			(1 << _object_type_projectile) |
			(1 << _object_type_scenery) |
			(1 << _object_type_sound_scenery) |
			(1 << _object_type_crate) |
			(1 << _object_type_effect_scenery) |
			_object_type_mask_device |
			_object_type_mask_item |
			_object_type_mask_motor |
			_object_type_mask_unit
	};

	struct object_type_definition
	{
		const char *name;
		tag group_tag;
		short datum_size;
		short placement_tag_block_offset;
		short palette_tag_block_offset;
		short placement_tag_block_size;
		long_flags placement_flags;
		long unknown14;
		void *mover_definition_data;
		void(__cdecl *_initialize)();
		void(__cdecl *_dispose)();
		void(__cdecl *_initialize_for_new_map)();
		void(__cdecl *_dispose_from_old_map)();
		void(__cdecl *_adjust_placement)();
		void(__cdecl *_disconnect_from_structure_bsp)();
		void(__cdecl *_place)();
		void(__cdecl *_new)();
		void(__cdecl *_update)();
		long *_proc40[7];
		void(__cdecl *export_function_values)();
		long *_proc60[5];
		void(__cdecl *handle_deleted_object)();
		long *unknown68[13];
		object_type_definition *type_definitions[16];
		object_type_definition *next;
		long unknown108;
		short unknown10C;
		short unknown10E;
	};
	static_assert(sizeof(object_type_definition) == 0xF8);
}