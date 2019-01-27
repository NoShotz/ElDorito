#pragma once

#include "cseries\cseries.hpp"

namespace blam
{
	enum tag_enum_type : long_enum
	{
		_tag_enum_char,
		_tag_enum_short,
		_tag_enum_long,
		_tag_enum_byte,
		_tag_enum_word,
		_tag_enum_dword
	};

	struct tag_enum_option
	{
		const char *name;
		const long value;

		tag_enum_option(const char *name, const long value);

		tag_enum_option &operator=(const tag_enum_option &);
	};

	struct tag_enum_definition
	{
		const char *name;
		const tag_enum_type type;
		const tag_enum_option *options;

		tag_enum_definition(const char *name, const tag_enum_type &type, const tag_enum_option *options);

		tag_enum_definition &operator=(const tag_enum_definition &);
	};

	struct tag_field_definition;

	struct tag_struct_definition
	{
		const char *name;
		const long size;
		const tag_field_definition *fields;

		tag_struct_definition(const char *name, const long size, const tag_field_definition *fields);

		tag_struct_definition &operator=(const tag_struct_definition &);
	};

	enum tag_field_type : long_enum
	{
		_field_tag,
		_field_string,
		_field_long_string,
		_field_string_id,
		_field_char_integer,
		_field_short_integer,
		_field_long_integer,
		_field_int64_integer,
		_field_byte_integer,
		_field_word_integer,
		_field_dword_integer,
		_field_qword_integer,
		_field_char_enum,
		_field_short_enum,
		_field_long_enum,
		_field_byte_flags,
		_field_word_flags,
		_field_long_flags,
		_field_angle,
		_field_point_2d,
		_field_rectangle_2d,
		_field_rgb_color,
		_field_argb_color,
		_field_real,
		_field_real_fraction,
		_field_real_point_2d,
		_field_real_point3d,
		_field_real_vector_2d,
		_field_real_vector_3d,
		_field_real_quaternion,
		_field_real_euler_angles_2d,
		_field_real_euler_angles_3d,
		_field_real_plane_2d,
		_field_real_plane_3d,
		_field_real_rgb_color,
		_field_real_argb_color,
		_field_real_hsv_color,
		_field_real_ahsv_color,
		_field_short_integer_bounds,
		_field_angle_bounds,
		_field_real_bounds,
		_field_fraction_bounds,
		_field_tag_reference,
		_field_block,
		_field_long_block_flags,
		_field_word_block_flags,
		_field_byte_block_flags,
		_field_char_block_index,
		_field_custom_char_block_index,
		_field_short_block_index,
		_field_custom_short_block_index,
		_field_long_block_index,
		_field_custom_long_block_index,
		_field_data,
		_field_vertex_buffer,
		_field_pad,
		_field_skip,
		_field_explanation,
		_field_custom,
		_field_struct,
		_field_array,
		_field_pageable_resource,
		_field_terminator
	};

	struct tag_field_definition
	{
		const tag_field_type type;
		const tag_field_type array_type;
		const char *name;
		const long length;
		union
		{
			const tag_enum_definition *enum_definition;
			const tag_struct_definition *struct_definition;
		};

		tag_field_definition(const tag_field_type &type);
		tag_field_definition(const tag_field_type &type, const long length);
		tag_field_definition(const tag_field_type &type, const char *name);
		tag_field_definition(const tag_field_type &type, const char *name, const tag_enum_definition *enum_definition);
		tag_field_definition(const tag_field_type &type, const char *name, const tag_struct_definition *struct_definition);
		tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length);
		tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length, const tag_enum_definition *enum_definition);
		tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length, const tag_struct_definition *struct_definition);

		tag_field_definition &operator=(const tag_field_definition &);
	};
}