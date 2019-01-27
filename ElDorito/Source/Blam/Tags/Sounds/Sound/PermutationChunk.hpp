#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>

namespace Blam::Tags::Sounds
{
	struct PermutationChunk
	{
		int32_t Offset;
		int32_t EncodedSize;
		int32_t RuntimeIndex;
		int32_t UnknownA;
		int32_t UnknownSize;
	};
	TAG_STRUCT_SIZE_ASSERT(PermutationChunk, 0x14);
}