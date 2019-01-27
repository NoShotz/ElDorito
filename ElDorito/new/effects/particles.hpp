#pragma once
#include <cseries\cseries.hpp>
#include <tag_files\tag_groups.hpp>
#include <tag_files\tag_mapping.hpp>
#include <shaders\render_method.hpp>

namespace blam
{
	enum { k_particle_group_tag = 'prt3' };

	struct particle
	{
		long_flags flags;
		tag_block attachments;
		long_flags appearance_flags;
		short_enum particle_billboard_style;
		short runtime_m_texture_array_size;
		short first_sequence_index;
		short sequence_count;
		float low_resolution_switch_distance;
		real_point2d center_offset;
		float curvature;
		float angle_fade_range;
		float motion_blur_translation_scale;
		float motion_blur_rotation_scale;
		float motion_blur_aspect_scale;
		render_method render_method;
		tag_mapping aspect_ratio;
		tag_mapping color;
		tag_mapping intensity;
		tag_mapping alpha;
		long_flags animation_flags;
		tag_mapping frame_index;
		tag_mapping animation_rate;
		tag_mapping palette_animation;
		tag_reference particle_model;
		dword runtime_m_used_particle_states;
		dword runtime_m_constant_per_particle_properties;
		dword runtime_m_constant_over_time_properties;
		tag_block runtime_m_sprites;
		tag_block runtime_m_frames;
		long : 32;
		long : 32;
		long : 32;
	};
	static_assert(sizeof(particle) == 0x1A0);
}