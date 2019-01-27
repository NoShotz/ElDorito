#pragma once
#include <cseries\cseries.hpp>
#include <memory\resources.hpp>
#include <tag_files\tag_groups.hpp>

#include <Blam\Geometry\RenderGeometry.hpp>

namespace blam
{
	enum structure_bsp_flags : word_flags
	{
		_bsp_has_instance_groups = 0x1,
		_bsp_surface_to_triangle_mapping_remapped = 0x2,
		_bsp_external_references_converted_to_io = 0x4,
		_bsp_structure_mopp_needs_rebuilt = 0x8,
		_bsp_structure_prefab_materials_need_postprocessing = 0x10,
		_bsp_serialized_havok_data_converted_to_target_platform = 0x20,
	};

	enum structure_bsp_content_policy_flags : word_flags
	{
		_bsp_has_working_pathfinding = 0x1,
		_bsp_convex_decomposition_enabled = 0x2,
	};

	struct structure_bsp_plane
	{
		short cluster_index1;
		short cluster_index2;
	};
	static_assert(sizeof(structure_bsp_plane) == 0x4);

	enum structure_bsp_instanced_geometry_flags : word_flags
	{
		_structure_bsp_instanced_geometry_contains_split_lighting_parts = 0x1,
		_structure_bsp_instanced_geometry_render_only = 0x2,
		_structure_bsp_instanced_geometry_does_not_block_aoe_damage = 0x4,
		_structure_bsp_instanced_geometry_collidable = 0x8,
		_structure_bsp_instanced_geometry_contains_decal_parts = 0x10,
		_structure_bsp_instanced_geometry_contains_water_parts = 0x20,
		_structure_bsp_instanced_geometry_negative_scale = 0x40,
		_structure_bsp_instanced_geometry_outside_map = 0x80,
		_structure_bsp_instanced_geometry_seam_colliding = 0x100,
		_structure_bsp_instanced_geometry_contains_deferred_reflections = 0x200,
		_structure_bsp_instanced_geometry_remove_from_shadow_geometry = 0x400,
		_structure_bsp_instanced_geometry_cinema_only = 0x800,
		_structure_bsp_instanced_geometry_exclude_from_cinema = 0x1000,
		_structure_bsp_instanced_geometry_disable_fx = 0x2000,
		_structure_bsp_instanced_geometry_disable_play_collision = 0x4000,
		_structure_bsp_instanced_geometry_disable_bullet_collision = 0x8000,
	};

	enum scenery_pathfinding_policy : short
	{
		_scenery_pathfinding_cut_out = 0x0,
		_scenery_pathfinding_static = 0x1,
		_scenery_pathfinding_dynamic = 0x2,
		_scenery_pathfinding_none = 0x3,
	};

	enum scenery_lightmapping_policy : short
	{
		_scenery_lightmapping_per_vertex = 0x0,
		_scenery_lightmapping_per_pixel_not_implemented = 0x1,
		_scenery_lightmapping_dynamic = 0x2,
	};

	struct structure_bsp_instanced_geometry
	{
		real scale;
		real_vector3d forward;
		real_vector3d left;
		real_vector3d up;
		real_point3d position;
		short instance_definition;
		short _bf36;
		short mesh_index;
		short compression_index;
		dword seam_bit_vector;
		real_point3d world_bounding_sphere_center;
		real_bounds bounding_sphere_radius_bounds;
		string_id name;
		scenery_pathfinding_policy pathfinding_policy;
		scenery_lightmapping_policy lightmapping_policy;
		real lightmap_resolution_scale;
		tag_block collision_definitions;
		short unknown4;
		short unknown5;
		short unknown6;
		short unknown7;
	};
	static_assert(sizeof(structure_bsp_instanced_geometry) == 0x74);

	struct structure_bsp_cluster
	{
		real_bounds bounds_x;
		real_bounds bounds_y;
		real_bounds bounds_z;
		char unknown;
		char scenario_sky_index;
		char camera_effect_index;
		char unknown2;
		short background_sound_environment_index;
		short sound_clusters_a_index;
		short unknown3;
		short unknown4;
		short unknown5;
		short unknown6;
		short unknown7;
		short runtime_decal_start_index;
		short runtime_decal_entry_count;
		short flags;
		dword unknown8;
		dword unknown9;
		dword unknown10;
		tag_block portals;
		int unknown11;
		short size;
		short count;
		int offset;
		int unknown12;
		dword unknown13;
		dword unknown14;
		tag_reference bsp;
		int cluster_index;
		int unknown15;
		short size2;
		short count2;
		int offset2;
		int unknown16;
		dword unknown17;
		dword unknown18;
		dword unknown19;
		tag_block collision_mopp_codes;
		short mesh_index;
		short unknown20;
		tag_block seams;
		tag_block decorator_grids;
		dword unknown21;
		dword unknown22;
		dword unknown23;
		tag_block object_placements;
		tag_block unknown25;
	};
	static_assert(sizeof(structure_bsp_cluster) == 0xDC);

	struct scenario_structure_bsp_definition
	{
		int bsp_checksum;
		structure_bsp_flags flags;
		structure_bsp_content_policy_flags content_policy_flags;
		structure_bsp_content_policy_flags failed_content_policy_flags;
		short unknown2;
		dword unknown3;
		tag_block seam_identifiers;
		tag_block unknown_raw7ths;
		tag_block collision_materials;
		tag_block leaves;
		real_bounds world_bounds_x;
		real_bounds world_bounds_y;
		real_bounds world_bounds_z;
		tag_block unknown_raw6ths;
		tag_block unknown_raw1sts;
		dword unknown15;
		dword unknown16;
		dword unknown17;
		tag_block cluster_portals;
		tag_block unknown14;
		tag_block fog;
		tag_block camera_effects;
		dword unknown18;
		dword unknown19;
		dword unknown20;
		tag_block detail_objects;
		tag_block clusters;
		tag_block materials;
		tag_block sky_owner_cluster;
		tag_block conveyor_surfaces;
		tag_block breakable_surfaces;
		tag_block pathfinding_data;
		dword unknown30;
		dword unknown31;
		dword unknown32;
		tag_block background_sound_environment_palette;
		dword unknown33;
		dword unknown34;
		dword unknown35;
		dword unknown36;
		dword unknown37;
		dword unknown38;
		dword unknown39;
		dword unknown40;
		dword unknown41;
		dword unknown42;
		dword unknown43;
		tag_block markers;
		tag_block lights;
		tag_block runtime_lights;
		tag_block runtime_decals;
		tag_block environment_object_palette;
		tag_block environment_objects;
		dword unknown45;
		dword unknown46;
		dword unknown47;
		dword unknown48;
		dword unknown49;
		dword unknown50;
		dword unknown51;
		dword unknown52;
		dword unknown53;
		dword unknown54;
		tag_block instanced_geometry_instances;
		tag_block decorators;
		Blam::Geometry::RenderGeometry geometry;
		tag_block unknown_sound_clusters_a;
		tag_block unknown_sound_clusters_b;
		tag_block unknown_sound_clusters_c;
		tag_block transparent_planes;
		dword unknown64;
		dword unknown65;
		dword unknown66;
		tag_block collision_mopp_codes;
		dword unknown67;
		real_bounds collision_world_bounds_x;
		real_bounds collision_world_bounds_y;
		real_bounds collision_world_bounds_z;
		tag_block breakable_surface_mopp_codes;
		tag_block breakable_surface_key_table;
		dword unknown68;
		dword unknown69;
		dword unknown70;
		dword unknown71;
		dword unknown72;
		dword unknown73;
		Blam::Geometry::RenderGeometry geometry2;
		tag_block leaf_systems;
		dword unknown83;
		dword unknown84;
		dword unknown85;
		pageable_resource *collision_bsp_resource;
		int useless_padding3;
		pageable_resource *pathfinding_resource;
		int useless_padding4;
		int unknown86;
		dword unknown87;
		dword unknown88;
		dword unknown89;
	};
	static_assert(sizeof(scenario_structure_bsp_definition) == 0x3AC);

	struct structure_bsp_cache_file_tag_resources
	{
		tag_block unknown_6ths;
		tag_block planes;
		tag_block unknown_7ths;
		tag_block pathfinding_data;
	};
	static_assert(sizeof(structure_bsp_cache_file_tag_resources) == 0x30);

	struct structure_bsp_unknown_6th
	{
		int plane_index;
		int plane_count;
	};
	static_assert(sizeof(structure_bsp_unknown_6th) == 0x8);

	struct global_collision_bsp_block
	{
		tag_block bsp3d_nodes;
		tag_block planes;
		tag_block leaves;
		tag_block bsp2d_references;
		tag_block bsp2d_nodes;
		tag_block surfaces;
		tag_block edges;
		tag_block vertices;
	};
	static_assert(sizeof(global_collision_bsp_block) == 0x60);

	struct global_collision_bsp_instance
	{
		real_quaternion position;
		real radius;
		global_collision_bsp_block collision_bsp;
		tag_block collision_geometries;
		tag_block collision_mopp_codes;
		tag_block unknown1;
		tag_block bsp3d_nodes;
		tag_block planes;
		unsigned short mesh_index;
		short compression_index;
		real unknown4;
		tag_block unknown5;
		real unknown6;
	};
	static_assert(sizeof(global_collision_bsp_instance) == 0xC8);

	struct global_collision_bsp_instance_unknown2
	{
		int first_index;
		int index_count;
	};
	static_assert(sizeof(global_collision_bsp_instance_unknown2) == 0x8);
}