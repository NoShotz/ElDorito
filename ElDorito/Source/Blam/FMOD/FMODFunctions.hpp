#pragma once
#include <cstdint>
#include "FMODEnum.hpp"
#include "FMODGlobals.hpp"

using namespace FMOD;

namespace FMOD::System {

	// sub_13884BA
	// This function is a wrapper for the real FMOD::System::PlaySound which has an extra function for the System class pointer.
	FMOD_RESULT PlaySoundWrapper(void* system1, void* system2, void* channelGroup, void* sound, bool paused, void* channel);

	// sub_4035E0
	int GetChannelCount();

	// sub_1395B83
	// This is System::Init function from FMOD. Apparently it is wrapped in the FMOD::EventSystemInit
	FMOD_RESULT Init(void* system, int maxChannels, FMOD_INITFLAGS flags, void* extraDriverData);

	// sub_01387A7F
	// This is some kind of wrapper for FMOD CreateSound.
	FMOD_RESULT CreateSound(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound);

	// sub_01387AD5
	FMOD_RESULT CreateStream(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound);
}

namespace FMOD::Sound {

	// sub_1388B2F
	FMOD_RESULT GetFormat(void* sound1, void* sound2, FMOD_SOUND_TYPE* type, FMOD_SOUND_FORMAT* format, int* channels, int* bits);
}

namespace Studio::System {

	// sub_1369AA0 
	FMOD_RESULT Init(void* system, int maxChannels, FMOD_INITFLAGS initFlags, void* extraDriverData, FMOD_STUDIO_INITFLAGS studioFlags);
}
