#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>

#include "..\SoundClasses\SoundClassEnum.hpp"
#include "Track.hpp"
#include "DetailSound.hpp"

namespace Blam::Tags::Sounds
{
	struct LoopingSound : TagGroup<'lsnd'>
	{
		int32_t Flags;
		float MartysMusicTime;
		float Unknown1;
		float Unknown2;
		float Unknown3;
		TagReference Unused;
		SoundClassShort SoundClass;
		int16_t Unknown4;
		TagBlock<Track> Tracks;
		TagBlock<DetailSound> DetailSounds;
	};
	TAG_STRUCT_SIZE_ASSERT(LoopingSound, 0x40);
}
