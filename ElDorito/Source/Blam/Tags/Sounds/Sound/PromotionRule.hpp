#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>

namespace Blam::Tags::Sounds
{
	struct PromotionRule
	{
		int16_t PitchRangeIndex;
		int16_t MaximumPlayingCount;
		float SupressionTime;
		int32_t Unknown1;
		int32_t Unknown2;
	};
	TAG_STRUCT_SIZE_ASSERT(PromotionRule, 0x10);
}