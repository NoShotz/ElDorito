#pragma once

#include "../Tags/Sounds/Sound/Sound.hpp"
#include "..\Tags\Sounds\SoundClasses/SoundClasses.hpp"
#include "..\Math\Random.hpp"

#include <math.h>
#include <iostream>

#include "SoundCache.hpp"
#include "SoundGlobals.hpp"

#include "../FMOD/FMODGlobals.hpp"
#include "../FMOD/FMODEnum.hpp"
#include "../FMOD/FMODFunctions.hpp"


namespace Blam::Sounds
{
	using namespace Blam::Tags::Sounds;
	using namespace Blam::SoundCache;

	void* tag_get(uint32_t tagGroup, int16_t tagIndex);

	//0x661C20
	int16_t sound_get_pitch_range_by_pitch(Sound* sound, float pitchModifier, int16_t fallbackIndex);

	//0x661D70
	double sound_sub_661D70(int16_t soundTagIndex, int32_t pitchRangeIndex);

	//0x661EF0
	double sound_get_distance_d(int16_t soundTagIndex);

	//0x661FC0
	double sound_get_distance_c(int16_t soundTagIndex);

	//0x68CE40
	bool sound_is_valid_pitch_range_permutation(int32_t soundTagIndex, int8_t* data);

	//0x662A40
	double sound_compute_pitch_modifier_min(Sound* sound, PitchRange* pitchRange, uint32_t SampleSize);

	//0x662120
	double unknown(int32_t soundTagIndex, int32_t pitchRangeIndex, int32_t permutationIndex, float parameter);

	//0x515910
	void PredictFirstPermutation(int16_t soundTagIndex);

	//0x64BD10
	FMOD_RESULT SoundCreateFMODSound(Blam::SoundTagDataStruct* data, void* sound, char* a3);

	//0x51B350
	int8_t UpdateSound(int32_t soundDatum0x38Index, float volume, int a3);

	float GetGainUpperBound(Sound* sound);

	float GetGainLowerBound(Sound* sound);

	ClassProperty* GetClassProperty(SoundClass type);

}
