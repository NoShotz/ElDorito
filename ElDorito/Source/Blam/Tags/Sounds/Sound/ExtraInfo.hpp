#pragma once

#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	struct ExtraInfo
	{
		uint32_t FillMe;
	};
	TAG_STRUCT_SIZE_ASSERT(ExtraInfo, 0x4);
}