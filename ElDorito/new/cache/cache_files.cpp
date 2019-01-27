#include "cache\cache_files.hpp"

#include <cstdio>

namespace blam
{
	string_id_cache::string_id_cache() : string_id_cache_header(),
		data(nullptr), strings(nullptr)
	{
	}

	string_id_cache::~string_id_cache()
	{
		if (strings)
			delete strings;

		if (data)
			delete data;
	}

	bool string_id_cache::load(const char *path)
	{
		FILE *stream;

		if (!fopen_s(&stream, path, "r"))
			return false;

		long offset = 0;

		fseek(stream, offset, SEEK_SET);
		fread(this, sizeof(string_id_cache_header), 1, stream);
		offset += sizeof(string_id_cache_header);

		data = new char[data_length];
		strings = new char *[string_count];
		
		long *string_offsets = new long[string_count];

		fseek(stream, offset, SEEK_SET);
		fread(string_offsets, sizeof(long), string_count, stream);
		offset += sizeof(long) * string_count;

		fseek(stream, offset, SEEK_SET);
		fread(data, sizeof(char), data_length, stream);

		fclose(stream);

		for (dword string_index = 0; string_index < string_count; string_index++)
		{
			offset = string_offsets[string_index];

			if (offset < 0 || (dword)offset >= data_length)
				continue;

			strings[string_index] = data + offset;
		}

		delete string_offsets;

		return true;
	}

	const char *string_id_cache::operator[](const string_id) const
	{
		return nullptr;
	}
}