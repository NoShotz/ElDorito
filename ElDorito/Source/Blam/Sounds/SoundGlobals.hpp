#pragma once
#include "SoundDatum.hpp"

namespace Blam{

	extern DataArray<XboxSoundDatum>** xboxSounds;
	extern DataArray<SoundPlaybackControllerDatum>** soundPlaybackControllers;
	extern DataArray<SoundSourceDatum>** soundSources;
	extern DataArray<LoopingSoundDatum>** loopingSounds;
	extern DataArray<SoundEffectDatum>** soundEffects;
	extern DataArray<SoundTrackerDatum>** soundTrackerData;
	extern SoundDataUnknown* soundUnknown;

	//TODO reimplement them within ED
	extern int32_t* globalSampleRates;
	extern int32_t* globalEncodings;
	extern SoundGlobalData* soundGlobals;
}