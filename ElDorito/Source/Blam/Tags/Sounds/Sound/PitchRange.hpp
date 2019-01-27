#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>
#include "Permutation.hpp"

namespace Blam::Tags::Sounds
{
	struct PitchRange
	{
		Text::StringID Name;
		int16_t NaturalPitch;
		int16_t Unknown1;
		Math::Bounds<int16_t> Bend;
		Math::Bounds<int16_t> MaxGainPitch;
		Math::Bounds<int16_t> Unknown2;
		uint32_t Unknown3;
		uint32_t Unknown4;
		uint32_t Unknown5;
		uint32_t Unknown6;
		int16_t Unknown7;
		int16_t Unknown8;
		uint8_t PermutationCount;
		uint8_t Unknown9;
		int16_t Unknown10;
		TagBlock<Permutation> Permutations;
	};
	TAG_STRUCT_SIZE_ASSERT(PitchRange, 0x38);
}