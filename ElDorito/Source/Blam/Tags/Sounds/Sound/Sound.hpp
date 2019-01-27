#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>

#include "../SoundClasses/SoundClassEnum.hpp"

#include "ImportTypeEnum.hpp"
#include "SampleRateEnum.hpp"
#include "Scale.hpp"
#include "PlaybackParameters.hpp"
#include "PlatformCodec.hpp"
#include "Promotion.hpp"
#include "PitchRange.hpp"
#include "CustomPlayback.hpp"
#include "Language.hpp"
#include "ExtraInfo.hpp"

namespace Blam::Tags::Sounds
{
	struct Sound : TagGroup<'snd!'>
	{
		uint32_t Flags;
		uint32_t Unknown1;
		uint32_t IsDialogue;
		SoundClass SoundClass;
		SampleRate SampleRate;
		uint8_t Unknown2;
		ImportType ImportType;
		PlaybackParameters PlaybackParameters;
		Scale Scale;
		PlatformCodec PlatformCodec;
		Promotion Promotion;
		int32_t Unknown4;
		int32_t Unknown5;
		int32_t Unknown6;
		int32_t Unknown7;
		uint32_t TotalSampleSize;
		int32_t Unknown8;
		TagBlock<PitchRange> PitchRanges;
		TagBlock<CustomPlayback> CustomPlaybacks;
		TagBlock<ExtraInfo> ExtraInfos;
		TagBlock<Language> Languages;
		uint32_t Resource;
		uint32_t Padding;
	};
	TAG_STRUCT_SIZE_ASSERT(Sound, 0xD4);

	//
	// Tag related functions
	//

	Scale* GetScale(Sound* sound);

	PlaybackParameters* GetPlaybackParameters(Sound* sound);

	SampleRate GetSampleRate(Sound* sound);

	PitchRange* GetPitchRange(Sound* sound, int32_t index);

	Permutation* GetPermutation(PitchRange* pitchRange, int32_t index);

	PermutationChunk* GetPermutationChunk(Permutation* permutation, int32_t index);

	int32_t GetPitchRangeCount(Sound* sound);

	int32_t GetPermutationCount(PitchRange* pitchRange);
	
	int32_t GetPermutationChunkCount(Permutation* permutation);

	int8_t GetCompression(Sound* sound);

	int8_t GetLoadMode(Sound* sound);

	int8_t GetEncoding(Sound* sound);

	int32_t GetNextPermutationChunkIndex(Permutation* permutation, int32_t currentIndex);

	Math::Bounds<int16_t>* GetBendBounds(PitchRange* pitchRange);

}
