#include "Camera.hpp"

#include "../Blam/BlamObjects.hpp"
#include "../Modules/ModuleCamera.hpp"

#include <game\game.hpp>

#include <cstdint>

namespace
{
	float GetScriptedCameraFovHook();
	void DeadCameraFovHook();
	void __fastcall c_following_camera__update_hook(void *ptr, void *unused, int localPlayerIndex, int a4, uint8_t *state);

	bool LodIncreased = false;
}

namespace Patches::Camera
{
	void ApplyAll()
	{
		Hook(0x32E18C, GetScriptedCameraFovHook, HookFlags::IsCall).Apply();
		Hook(0x2122C5, DeadCameraFovHook).Apply();
		Pointer(0x016724DC).Write(uint32_t(&c_following_camera__update_hook));
	}

	const char *IncreaseLOD()
	{
		std::string result;
		// LOD patches compliments of zedd
		// Patch for lod dword_176DB40 (2.0) -> dword_176DB50 (10.0)
		// Patch to apply cine lod to everything
		if (!LodIncreased)
		{
			memset(Pointer(0xA65EBB), 0x50, 1);
			memset(Pointer(0xA1962C), 0x90, 2);
			LodIncreased = true;
			result = "Lod Unlocked: True";
		}
		else
		{
			memset(Pointer(0xA65EBB), 0x40, 1);
			memset(Pointer(0xA1962C), 0x74, 1);
			memset(Pointer(0xA1962D), 0x10, 1);
			LodIncreased = false;
			result = "Lod Unlocked: False";
		}
		return result.c_str();
	}
}

namespace
{
	float GetScriptedCameraFovHook()
	{
		auto fov = 0.0f;

		if (blam::game_is_mainmenu())
		{
			fov = 70.0f;
		}
		else
		{
			auto scriptedCameraFov = *(float*)0x018ECE00;
			if (scriptedCameraFov == 0.0f)
				fov = *(float*)0x18BB1C8;
			else
				fov = scriptedCameraFov;
		}

		return fov * 0.017453292f;
	}

	float *GetPreferedCameraFovPointer()
	{
		return &Modules::ModuleCamera::Instance().VarCameraFov->ValueFloat;
	}

	__declspec(naked) void DeadCameraFovHook()
	{
		__asm
		{
			test dword ptr[ecx], 0x800
			jnz NOT_DEAD
			pushad
			call GetPreferedCameraFovPointer
			movss xmm0, [eax]
			popad
			mov eax, 0x006122E0
			jmp eax
			NOT_DEAD:
			mov eax, 0x0061230A
			jmp eax
		}
	}

	void __fastcall c_following_camera__update_hook(void *thisptr, void *unused, int localPlayerIndex, int a4, uint8_t *state)
	{
		struct s_camera_definition
		{
			Blam::Math::RealVector3D Position;
			Blam::Math::RealVector3D PositionShift;
			float LookShift[2];
			float Depth;
			float FieldOfView;
			Blam::Math::RealVector3D Forward;
			Blam::Math::RealVector3D Up;
			// ...
		};

		const auto c_following_camera__update = (void(__thiscall *)(void *ptr, int localPlayerIndex, int a4, uint8_t *state))(0x00729730);
		const auto &moduleCamera = Modules::ModuleCamera::Instance();

		c_following_camera__update(thisptr, localPlayerIndex, a4, state);

		auto &definition = *(s_camera_definition*)(state + 0x4);

		// scale fov by prefered fov
		definition.FieldOfView = definition.FieldOfView / moduleCamera.VarCameraFov->DefaultValueFloat * moduleCamera.VarCameraFov->ValueFloat;

		// scale position shift and depth with target object scale
		auto targetObjectIndex = *(uint32_t*)((uint8_t*)thisptr + 0x4);
		if (targetObjectIndex == -1)
			return;
		auto targetObject = Blam::Objects::Get(targetObjectIndex);
		if (!targetObject)
			return;	
		auto s = (float)std::pow(targetObject->Scale, 0.5);
		definition.Depth *= s;
		definition.PositionShift *= s;
	}
}
