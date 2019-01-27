#include "FMODFunctions.hpp"

using namespace FMOD;

namespace FMOD::System {

	FMOD_RESULT PlaySoundWrapper(void* system1, void* system2, void* channelGroup, void* sound, bool paused, void* channel) {

		static auto sub_13884BA = (FMOD_RESULT(__thiscall *)(void* thisptr, void* system, void* channelGroup, void* sound, bool paused, void* channel))(0x13884BA);
		return sub_13884BA(system1, system2, channelGroup, sound, paused, channel);
	}

	int GetChannelCount() {
		return FMOD_MAX_CHANNELS;
	}

	FMOD_RESULT Init(void* system, int maxChannels, FMOD_INITFLAGS flags, void* extraDriverData) {
		static auto sub_1395B83 = (FMOD_RESULT(__thiscall *)(void* system, int maxChannels, FMOD_INITFLAGS flags, void* extraDriverData))(0x1395B83);
		return sub_1395B83(system, maxChannels, flags, extraDriverData);
	}

	FMOD_RESULT CreateSound(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound) {
		static auto sub_1387A7F = (FMOD_RESULT(__thiscall *)(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound))(0x1387A7F);
		return sub_1387A7F(system1, system2, nameOrData, mode, exInfo, sound);
	}

	FMOD_RESULT CreateStream(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound) {
		static auto sub_1387AD5 = (FMOD_RESULT(__thiscall *)(void* system1, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound))(0x1387AD5);
		return sub_1387AD5(system1, system2, nameOrData, mode, exInfo, sound);
	}

}

namespace FMOD::Sound {

	FMOD_RESULT GetFormat(void* sound1, void* sound2, FMOD_SOUND_TYPE* type, FMOD_SOUND_FORMAT* format, int* channels, int* bits) {
		static auto sub_1388B2F = (FMOD_RESULT(__thiscall *)(void* sound1, void* sound2, FMOD_SOUND_TYPE* type, FMOD_SOUND_FORMAT* format, int* channels, int* bits))(0x1388B2F);
		return sub_1388B2F(sound1, sound2, type, format, channels, bits);
	}
}

namespace Studio::System {

	FMOD_RESULT Init(void* system, int maxChannels, FMOD_INITFLAGS initFlags, void* extraDriverData, FMOD_STUDIO_INITFLAGS studioFlags) {
		static auto sub_1369AA0 = (FMOD_RESULT(__stdcall *)(void* system, int maxchannels, FMOD_INITFLAGS initFlags, void*  extraDriverData, FMOD_STUDIO_INITFLAGS studioFlags))(0x1369AA0);
		return sub_1369AA0(system, maxChannels, initFlags, extraDriverData, studioFlags);
	}

}