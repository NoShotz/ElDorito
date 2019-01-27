#pragma once

#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	struct Language
	{
		uint32_t FillMe;
	};
	TAG_STRUCT_SIZE_ASSERT(Language, 0x4);
}