#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>

namespace Blam::Tags::Sounds
{
	struct RuntimeTimer
	{
		int32_t Unknown;
	};
	TAG_STRUCT_SIZE_ASSERT(RuntimeTimer, 0x4);
}