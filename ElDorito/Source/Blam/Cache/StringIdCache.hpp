#pragma once
#include <cstdint>
#include <iostream>
#include <string>

#include <Blam\Text\StringID.hpp>

namespace Blam::Cache
{
	struct StringIDCacheHeader
	{
		int32_t StringCount;
		int32_t StringDataSize;
	};

	struct StringIDCache
	{
		StringIDCacheHeader Header;
		char *Data;
		char **Strings;

		StringIDCache();
		~StringIDCache();

		static StringIDCache Instance;

		bool Load(const std::string &path);

		std::string GetString(const Text::StringID &stringID);
		Text::StringID GetStringID(const std::string &string);
	};
}

