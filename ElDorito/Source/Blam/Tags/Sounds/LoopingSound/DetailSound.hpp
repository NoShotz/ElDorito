#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>

namespace Blam::Tags::Sounds
{
	struct DetailSound {
		Text::StringID Name;
		TagReference Sound;
		Math::Bounds<float> RandomPeriodBounds;
		float Unknown1;
		int32_t Flags;
		Math::Bounds<float> YawBounds;
		Math::Bounds<float> PitchBounds;
		Math::Bounds<float> DistanceBounds;
	};
	TAG_STRUCT_SIZE_ASSERT(DetailSound, 0x3C);
}