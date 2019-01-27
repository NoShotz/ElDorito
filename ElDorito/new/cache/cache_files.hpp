#pragma once

#include "cseries\cseries.hpp"

namespace blam
{
	struct string_id_cache_header
	{
		dword string_count;
		dword data_length;
	};

	struct string_id_cache : string_id_cache_header
	{
		char *data;
		char **strings;

		string_id_cache();
		~string_id_cache();

		bool load(const char *path);

		const char *operator[](const string_id id) const;
	};
}