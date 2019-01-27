#pragma once

#include "cseries\cseries.hpp"
#include "memory\data.hpp"

namespace blam
{
	struct tag_group
	{
		tag group_tag;
		tag parent_group_tag;
		tag grandparent_group_tag;
		string_id group_name;

		static const tag_group none;

		tag_group();
		tag_group(const tag group_tag, const string_id group_name);
		tag_group(const tag group_tag, const tag parent_group_tag, const string_id group_name);
		tag_group(const tag group_tag, const tag parent_group_tag, const tag grandparent_group_tag, const string_id group_name);
		tag_group(const tag_group &other);

		bool operator==(const tag_group &other) const;
		bool operator!=(const tag_group &other) const;

		operator bool() const;
	};
	static_assert(sizeof(tag_group) == 0x10);

	struct tag_reference
	{
		tag group_tag;
		long : 32;
		long : 32;
		datum_index tag_index;

		static const tag_reference none;

		tag_reference();
		tag_reference(const tag group_tag, const datum_index tag_index);
		tag_reference(const tag_reference &other);

		void clear();
		void set(const tag new_group_tag, const datum_index new_tag_index);

		bool operator==(const tag_reference &other) const;
		bool operator!=(const tag_reference &other) const;

		operator bool() const;
	};
	static_assert(sizeof(tag_reference) == 0x10);

	struct tag_block
	{
		long count;
		void *address;
		long : 32;

		tag_block();
		tag_block(const long count, void *const address);
		tag_block(const tag_block &other);

		template <typename element_type>
		element_type &get_element(const long element_index) const
		{
			return ((element_type *)address)[element_index];
		}

		bool operator==(const tag_block &other) const;
		bool operator!=(const tag_block &other) const;

		operator bool() const;
	};
	static_assert(sizeof(tag_block) == 0xC);

	struct tag_data
	{
		long size;
		long : 32;
		long : 32;
		void *address;
		long : 32;

		tag_data();
		tag_data(const long size, void *const address);
		tag_data(const tag_data &other);

		template <typename element_type>
		element_type &get_element(const long element_index) const
		{
			return ((element_type *)address)[element_index];
		}

		bool operator==(const tag_data &other) const;
		bool operator!=(const tag_data &other) const;

		operator bool() const;
	};
	static_assert(sizeof(tag_data) == 0x14);
}