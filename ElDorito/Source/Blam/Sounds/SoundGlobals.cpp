#include "SoundGlobals.hpp"

namespace Blam {

	DataArray<XboxSoundDatum>** xboxSounds = reinterpret_cast<DataArray<XboxSoundDatum>**>(0x02497CF8);
	DataArray<SoundPlaybackControllerDatum>** soundPlaybackControllers = reinterpret_cast<DataArray<SoundPlaybackControllerDatum>**>(0x02497D3C);
	DataArray<SoundSourceDatum>** soundSources = reinterpret_cast<DataArray<SoundSourceDatum>**>(0x0238E860);
	DataArray<LoopingSoundDatum>** loopingSounds = reinterpret_cast<DataArray<LoopingSoundDatum>**>(0x02497D20);
	DataArray<SoundEffectDatum>** soundEffects = reinterpret_cast<DataArray<SoundEffectDatum>**>(0x02497D30);
	DataArray<SoundTrackerDatum>** soundTrackerData = reinterpret_cast<DataArray<SoundTrackerDatum>**>(0x002497D4C);
	SoundDataUnknown* soundUnknown = reinterpret_cast<SoundDataUnknown*>(0x0238E85C);

	int32_t* globalSampleRates = reinterpret_cast<int32_t*>(0x0166B1F0);
	int32_t* globalEncodings = reinterpret_cast<int32_t*>(0x0166B1FC);
	SoundGlobalData* soundGlobals = reinterpret_cast<SoundGlobalData*>(0x0238E858);

}