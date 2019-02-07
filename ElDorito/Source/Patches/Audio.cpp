#include "../Patch.hpp"
#include "Audio.hpp"
#include "../Modules/ModuleSettings.hpp"
#include "../Blam/FMOD/FMODFunctions.hpp"
#include "../Blam/FMOD/FMODEnum.hpp"
#include "../Blam/Sounds/SoundDatum.hpp"
#include "../Blam/Sounds/Functions.hpp"
#include "../Blam/Sounds/SoundGlobals.hpp"
#include <iostream>


namespace
{
	int __fastcall FMOD_Sound_GetFormat_Hook(void* sound1, void* unused, void* sound2, FMOD_SOUND_TYPE* type, FMOD_SOUND_FORMAT* format, int* channels, int* bits);
	int __fastcall FMOD_System_PlaySound_Wrapper_Hook(void* system1, void* unused, void* system2, void* channelGroup, void* sound, int paused, void* channel);
	int __fastcall FMOD_System_CreateSound_Hook(void* system1, void* unused, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound);
	int __cdecl CreateSoundFMOD(Blam::SoundTagDataStruct* data, void* sound, char* a3);

	int __stdcall FMOD_Studio_Init_Hook(void* system, int maxChannels, int flags, void* extraDriverData, int studioFlags);
	bool __fastcall snd_SYSTEM_FMOD_Init_Hook(uint8_t* thisptr, void* unused, int a2, int a3);
	int16_t sub_661C20_hook(void *sndDef, float pitchModifier, int16_t fallbackIndex);

	const auto s_HaloSoundSystemPtr = (void**)0x018BC9C8;

	char unk1[1024];
	char unk2[1024];

	void *__cdecl sub_51B070_hook(void *a1, void *a2, void *a3)
	{
		static const auto sub_51B070 = (void *(__cdecl *)(void *, void *, void *))0x51B070;

		memset(unk1, 0, 1024);
		memset(unk2, 0, 1024);

		return sub_51B070(a1, unk1, unk2);
	}

	void *__cdecl sub_51B7D0_hook(int a1, int a2)
	{
		static const auto sub_51B7D0 = (void *(__cdecl *)(void *, void *))0x51B7D0;

		memset(unk1, 0, 1024);
		memset(unk2, 0, 1024);

		return sub_51B7D0(unk1, unk2);
	}

	int __stdcall sub_1388659_hook(int a1, DWORD *a2)
	{
		static const auto sub_1388659 = (int(__stdcall *)(int a2, DWORD *a3))0x1388659;

		a2[1] = 64;
		a2[2] = 32;
		a2[3] = 32;
		a2[4] = 16;

		return sub_1388659(a1, a2);
	}
}

namespace Patches::Audio
{
	void ApplyAll()
	{
		// Adds the FMOD WASAPI output fix from FMODEx 4.44.56, which stops weird popping sound at startup
		Patch(0x100DA75, { 0x2 }).Apply();

		// increase fmod software channel count
		// http://www.fmod.org/docs/content/generated/FMOD_System_SetSoftwareChannels.html
		*reinterpret_cast<uint32_t*>(0x404DF9) = FMOD::FMOD_MAX_CHANNELS;

		// increase fmod max virtual audio channel count
		// http://www.fmod.org/docs/content/generated/FMOD_System_Init.html
		*(BYTE *)0x404EA0 = FMOD::FMOD_MAX_CHANNELS;
		*(BYTE *)0x404EC4 = FMOD::FMOD_MAX_CHANNELS;

		Pointer(0x01750794).Write(uint32_t(&FMOD_Studio_Init_Hook));
		Pointer(0x0176CA18).Write(uint32_t(&snd_SYSTEM_FMOD_Init_Hook));

		*reinterpret_cast<uint32_t*>(0x4035E1) = FMOD::FMOD_MAX_CHANNELS;

		*reinterpret_cast<uint32_t*>(0x517BE6) = 0;
		*reinterpret_cast<uint32_t*>(0x517AFC) = 0x3800;
		*reinterpret_cast<uint32_t*>(0x517B4C) = 0x3800;
		*reinterpret_cast<uint32_t*>(0x18BE324) = 0x700070;
		*reinterpret_cast<uint32_t*>(0x18BE328) = 0xC0012;
		*reinterpret_cast<uint32_t*>(0x667728) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x667736) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x667744) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x667752) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x667760) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x518F86) = FMOD::FMOD_MAX_CHANNELS;
		*reinterpret_cast<uint32_t*>(0x518F94) = FMOD::FMOD_MAX_CHANNELS;

		// prevent invalid pitch range index from being returned and causing crashes
		Hook(0x264E39, sub_661C20_hook, HookFlags::IsCall).Apply();

		Hook(0x118FC4, sub_51B070_hook, HookFlags::IsCall).Apply();
		Hook(0x119036, sub_51B7D0_hook, HookFlags::IsCall).Apply();

		Hook(0x4E29, sub_1388659_hook, HookFlags::IsCall).Apply();
	}

	bool SetOutputDevice(int deviceIndex)
	{
		static auto FMOD_System_SetDriver = (int(__thiscall *)(void *fmodSoundSystem, int driver))(0x139771C);

		auto soundSystem = *s_HaloSoundSystemPtr;
		if (!soundSystem)
			return false;
		auto fmodSystem = *((void**)(soundSystem)+1);
		if (!fmodSystem)
			return false;

		return FMOD_System_SetDriver(fmodSystem, deviceIndex) == 0;
	}
}

namespace
{
	using namespace Blam;
	using namespace std;

	int __cdecl CreateSoundFMOD(Blam::SoundTagDataStruct* data, void* sound, char* a3) {
		//static auto sub_64BD10 = (int(__cdecl*)(Blam::SoundTagDataStruct* data, void* sound, char* a3))(0x64BD10);

		auto tagIndex = data->SoundTagIndex;
		auto name = Blam::Tags::TagInstance::GetTagName(tagIndex);

		auto soundSource = (*soundSources)->Get(data->SoundSourcesHandle);

		cout << "Creating sound: " << name << endl;
		cout << "Pitch range: " << (int)soundSource->PitchRangeBlockIndex << " Permutation: " << (int)soundSource->PitchRangePermutationBlockIndex << endl;
		auto result = Blam::Sounds::SoundCreateFMODSound(data, sound, a3);

		if (soundSource->LoopingSoundDatumHandle.Index) {
			auto loopingSoundData = (*loopingSounds)->Get(soundSource->LoopingSoundDatumHandle);

			if (loopingSoundData != nullptr)
				cout << "lsnd track index: " << (int)soundSource->LoopingSoundTrackIndex << endl;
			cout << "Track1 indices 0xC: " << (int)loopingSoundData->Track1.SoundEnumType1 << " 0xD: " << (int)loopingSoundData->Track1.SoundEnumType2 << endl;
		}



		if (result != 0)
			cout << "Failed to create sound, error code " << result << std::endl;

		return result;
	}


	int __fastcall FMOD_System_PlaySound_Wrapper_Hook(void* system1, void* unused, void* system2, void* channelGroup, void* sound, int paused, void* channel)
	{
		return FMOD::System::PlaySoundWrapper(system1, system2, channelGroup, sound, paused, channel);
	}

	int __fastcall FMOD_Sound_GetFormat_Hook(void* sound1, void* unused, void* sound2, FMOD_SOUND_TYPE* type, FMOD_SOUND_FORMAT* format, int* channels, int* bits)
	{
		return FMOD::Sound::GetFormat(sound1, sound2, type, format, channels, bits);
	}

	int __fastcall FMOD_System_CreateSound_Hook(void* system1, void* unused, void* system2, char* nameOrData, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo, void* sound)
	{
		return FMOD::System::CreateSound(system1, system2, nameOrData, mode, exInfo, sound);
	}

	// Intercept and change max number of channels in Studio::Init (also changes FMOD::System within the init function)
	int __stdcall FMOD_Studio_Init_Hook(void* system, int maxChannels, int flags, void* extraDriverData, int studioFlags)
	{
		return Studio::System::Init(system, FMOD_MAX_CHANNELS, (FMOD::FMOD_INITFLAGS)flags, extraDriverData, (Studio::FMOD_STUDIO_INITFLAGS)(studioFlags));
	}

	bool __fastcall snd_SYSTEM_FMOD_Init_Hook(uint8_t* thisptr, void* unused, int a2, int a3)
	{
		static auto snd_SYSTEM_FMOD_PrepareInit = (bool(*)())(0x00404D10);
		static auto sub_1353A80 = (bool(__stdcall*)(void *a1))(0x01353A80);
		static auto snd_SYSTEM_FMOD_InitEventSystem = (bool(__thiscall*)(void *thisptr, void* a2))(0x00404D70);
		static auto sub_64D9A0 = (bool(__thiscall *)(void* thisptr, int a2, int a3))(0x64D9A0);

		*(uint32_t*)0x0698D054 = GetCurrentThreadId(); // g_SoundThreadId

		if (!snd_SYSTEM_FMOD_PrepareInit() ||
			sub_1353A80((void*)(thisptr + 0x30)) ||
			(*(int(__stdcall **)(uint32_t, void *))(**(uint32_t **)(thisptr + 0x30) + 28))(*(uint32_t *)(thisptr + 0x30), (void*)0x69AD05C) ||
			!snd_SYSTEM_FMOD_InitEventSystem(thisptr, &a2))
		{
			return false;
		}

		auto haloSoundSystem = *s_HaloSoundSystemPtr;
		if (!haloSoundSystem || !sub_64D9A0(haloSoundSystem, a2, 1))
			return false;

		*(uint32_t *)(thisptr + 4) |= 1u;

		auto outputDevice = Modules::ModuleSettings::Instance().VarAudioOutputDevice->ValueInt;
		if (outputDevice)
			Patches::Audio::SetOutputDevice(outputDevice);

		return true;
	}

	// Temp hack to figure out what is the issue with the ported sounds causing this problem.
	int16_t sub_661C20_hook(void *sndDef, float pitchModifier, int16_t fallbackIndex)
	{
		const auto sub_661C20 = (int16_t(*)(void *sndDef, float pitchModifier, int16_t fallbackIndex))(0x661C20);
		auto ret = sub_661C20(sndDef, pitchModifier, fallbackIndex);
		if (ret == -1)
			ret = 0;
		return ret;
	}
}