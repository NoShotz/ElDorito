#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>
#include "OutputEffectEnum.hpp"

namespace Blam::Tags::Sounds
{
	struct Track {

		Text::StringID Name;
		int32_t Flags;
		float Gain;

		struct {
			float FadeInDuration;
			float Unknown1;
			float FadeOutDuration;
			int16_t Unknown2;
			int16_t Unknown3;
			TagReference In;
			TagReference Loop;
			TagReference Out;
			TagReference AlternateLoop;
			TagReference AlternateOut;
			OutputEffect OutputEffect;
			int16_t Unknown4;
			TagReference AlternateTransitionIn;
			TagReference AlternateTransitionOut;
			float AlternateCrossfadeDuration;
			float Unknown5;
			float AlternateFadeOutDuration;
			float Unknown6;
		}Tags;

	};
	TAG_STRUCT_SIZE_ASSERT(Track, 0xA0);
}