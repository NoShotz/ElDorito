#pragma once
#include <tag_files\tag_groups.hpp>
#include <tag_files\tag_mapping.hpp>

namespace blam
{
	enum { k_render_method_group_tag = 'rm  ' };

	struct render_method
	{
		tag_reference base_render_method;
		tag_block unknown;
		tag_block import_data;
		tag_block shader_properties;
		tag_mapping_variable_type input_variable;
		tag_mapping_variable_type range_variable;
		tag_mapping_output_modifier output_modifier;
		tag_mapping_variable_type output_modifier_input;
		real runtime_m_constant_value;
		word_flags runtime_m_flags;
		tag_mapping_flags force_flags;
		char : 8;
	};
	static_assert(sizeof(render_method) == 0x40);
}