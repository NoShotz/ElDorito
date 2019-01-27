#include "tag_files\tag_groups.hpp"

namespace blam
{
	const tag_group tag_group::none = { _tag_none, _string_id_invalid };

	tag_group::tag_group() :
		tag_group(none)
	{
	}

	tag_group::tag_group(const tag group_tag, const string_id group_name) :
		tag_group(group_tag, _tag_none, group_name)
	{
	}

	tag_group::tag_group(const tag group_tag, const tag parent_group_tag, const string_id group_name) :
		tag_group(group_tag, parent_group_tag, _tag_none, group_name)
	{
	}

	tag_group::tag_group(const tag group_tag, const tag parent_group_tag, const tag grandparent_group_tag, const string_id group_name) :
		group_tag(group_tag), parent_group_tag(parent_group_tag), grandparent_group_tag(grandparent_group_tag), group_name(group_name)
	{
	}

	tag_group::tag_group(const tag_group &other) :
		tag_group(other.group_tag, other.parent_group_tag, other.grandparent_group_tag, other.group_name)
	{
	}

	bool tag_group::operator==(const tag_group &other) const
	{
		return (group_tag == other.group_tag)
			&& (parent_group_tag == other.parent_group_tag)
			&& (grandparent_group_tag == other.grandparent_group_tag)
			&& (group_name == other.group_name);
	}

	bool tag_group::operator!=(const tag_group &other) const
	{
		return !(*this == other);
	}

	tag_group::operator bool() const
	{
		return *this != none;
	}

	const tag_reference tag_reference::none = { _tag_none, _datum_index_none };

	tag_reference::tag_reference() :
		tag_reference(none)
	{
	}

	tag_reference::tag_reference(const tag group_tag, const datum_index tag_index) :
		group_tag(group_tag), tag_index(tag_index)
	{
	}

	tag_reference::tag_reference(const tag_reference &other) :
		tag_reference(other.group_tag, other.tag_index)
	{
	}

	void tag_reference::clear()
	{
		group_tag = _tag_none;
		tag_index = _datum_index_none;
	}

	void tag_reference::set(const tag new_group_tag, const datum_index new_tag_index)
	{
		group_tag = new_group_tag;
		tag_index = new_tag_index;
	}

	bool tag_reference::operator==(const tag_reference &other) const
	{
		return (group_tag == other.group_tag)
			&& (tag_index == other.tag_index);
	}

	bool tag_reference::operator!=(const tag_reference &other) const
	{
		return !(*this == other);
	}

	tag_reference::operator bool() const
	{
		return *this != none;
	}

	tag_block::tag_block() :
		tag_block(0, nullptr)
	{
	}

	tag_block::tag_block(const long count, void *const address) :
		count(count), address(address)
	{
	}

	tag_block::tag_block(const tag_block &other) :
		tag_block(other.count, other.address)
	{
	}

	bool tag_block::operator==(const tag_block &other) const
	{
		return (count == other.count)
			&& (address == other.address);
	}

	bool tag_block::operator!=(const tag_block &other) const
	{
		return !(*this == other);
	}

	tag_block::operator bool() const
	{
		return (count > 0)
			&& (address != nullptr);
	}

	tag_data::tag_data() :
		tag_data(0, nullptr)
	{
	}

	tag_data::tag_data(const long size, void *const address) :
		size(size), address(address)
	{
	}

	tag_data::tag_data(const tag_data &other) :
		tag_data(other.size, other.address)
	{
	}

	bool tag_data::operator==(const tag_data &other) const
	{
		return (size == other.size)
			&& (address == other.address);
	}

	bool tag_data::operator!=(const tag_data &other) const
	{
		return !(*this == other);
	}

	tag_data::operator bool() const
	{
		return (size > 0)
			&& (address != nullptr);
	}
}