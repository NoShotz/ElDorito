#pragma once

#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	struct CustomPlayback
	{
		uint32_t FillMe;
	};
	TAG_STRUCT_SIZE_ASSERT(CustomPlayback, 0x4);
}