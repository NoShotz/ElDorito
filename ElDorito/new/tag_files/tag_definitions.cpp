#include "tag_files\tag_definitions.hpp"

namespace blam
{
	tag_enum_option::tag_enum_option(const char *name, const long value) :
		name(name), value(value)
	{
	}

	tag_enum_option &tag_enum_option::operator=(const tag_enum_option &)
	{
		return *this;
	}

	tag_enum_definition::tag_enum_definition(const char *name, const tag_enum_type &type, const tag_enum_option *options) :
		name(name), type(type), options(options)
	{
	}

	tag_enum_definition &tag_enum_definition::operator=(const tag_enum_definition &)
	{
		return *this;
	}

	tag_struct_definition::tag_struct_definition(const char *name, const long size, const tag_field_definition *fields) :
		name(name), size(size), fields(fields)
	{
	}

	tag_struct_definition &tag_struct_definition::operator=(const tag_struct_definition &)
	{
		return *this;
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type) :
		tag_field_definition(type, "")
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const long length) :
		tag_field_definition(type, _field_skip, "", length)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const char *name) :
		tag_field_definition(type, _field_skip, name, 1)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const char *name, const tag_enum_definition *enum_definition) :
		tag_field_definition(type, _field_skip, name, 1, enum_definition)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const char *name, const tag_struct_definition *struct_definition) :
		tag_field_definition(type, _field_skip, name, 1, struct_definition)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length) :
		type(type), array_type(array_type), name(name), length(length)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length, const tag_enum_definition *enum_definition) :
		type(type), array_type(array_type), name(name), length(length), enum_definition(enum_definition)
	{
	}

	tag_field_definition::tag_field_definition(const tag_field_type &type, const tag_field_type &array_type, const char *name, const long length, const tag_struct_definition *struct_definition) :
		type(type), array_type(array_type), name(name), length(length), struct_definition(struct_definition)
	{
	}

	tag_field_definition &tag_field_definition::operator=(const tag_field_definition &)
	{
		return *this;
	}
}