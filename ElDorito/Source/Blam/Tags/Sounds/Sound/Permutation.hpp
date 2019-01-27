#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>
#include "PermutationChunk.hpp"

namespace Blam::Tags::Sounds
{
	struct Permutation
	{
		Text::StringID Name;
		Math::Bounds<float> SkipFraction;
		uint32_t SampleSize;
		uint32_t PermutationNumber;
		uint32_t IsNotFirstPermutation;
		TagBlock<PermutationChunk> PermutationChunks;
		uint32_t Unknown1;
		uint32_t Unknown2;
	};
	TAG_STRUCT_SIZE_ASSERT(Permutation, 0x2C);
}