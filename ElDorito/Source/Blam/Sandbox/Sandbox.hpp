#pragma once

#include "../BlamTypes.hpp"
#include "../Math/RealVector3D.hpp"
#include "../Math/RealMatrix4x3.hpp"

namespace Blam::Sandbox
{
	struct ZoneShape
	{
		int Shape;
		int ShapeShader;
		float RadiusWidth;
		float Length;
		float Top;
		float Bottom;
		Math::RealMatrix4x3 Transform;
		float BoundingRadius;
	};
	static_assert(sizeof(ZoneShape) == 0x50, "Invalid ZoneShape size");

	struct SandboxGlobals
	{
		unsigned int Unknown00;
		unsigned int Unknown04;
		unsigned short PlayersInMonitorModeBitSet;
		unsigned short Unknown06;
		unsigned int HeldObjects[16];
		float HeldObjectDistances[16];
		Math::RealVector3D CrosshairPoints[16];
		Math::RealVector3D CrosshairIntersectNormals[16];
		Math::RealVector3D CrosshairDirections[16];
		unsigned int CrosshairObjects[16];
		unsigned char UnknownE49c[0x43c];
	};
	static_assert(sizeof(SandboxGlobals) == 0x748, "Invalid SandboxGlobals size");

	struct ForgeMessage
	{
		unsigned int Type;
		unsigned int TagIndex;
		unsigned int PlacementIndex;
		unsigned int PlayerIndex;
		unsigned int Unknown10;
		char QuotaMin;
		char QuotaMax;
		unsigned short Unknown16;
		Math::RealVector3D CrosshairPoint;
		unsigned int SelectedGameType;
		unsigned short EngineFlags;
		unsigned char Flags;
		unsigned char Team;
		unsigned char SharedStorage;
		unsigned char SpawnTime;
		unsigned char ObjectType;
		unsigned char ShapeType;
		unsigned int Unknown30;
		unsigned int Unknown34;
		unsigned int Unknown38;
		unsigned int Unknown3c;
	};
	static_assert(sizeof(ForgeMessage) == 0x40, "Invalid ForgeMessage size");

	const auto GetObjectZoneShape = (void(__cdecl *)(unsigned int objectIndex, ZoneShape* zoneShape, int a3))(0xBA0AD0);
	const auto PointIntersectsZone = (bool(__cdecl*)(const Math::RealVector3D* point, const ZoneShape* zone))(0x00BA11F0);
	const auto GetObjectTransformationMatrix = (void(__cdecl*)(unsigned int objectIndex, Math::RealMatrix4x3* outMatrix))(0x00B2EC60);
	const auto GetObjectPosition = (void(*)(unsigned int objectIndex, Math::RealVector3D *position))(0xB2E5A0);
	const auto SpawnObject = (unsigned int(__thiscall *)(Blam::MapVariant* thisptr, unsigned int tagIndex, int a3, int16_t placementIndex,
		const Math::RealVector3D *position, const Math::RealVector3D *rightVec, const Math::RealVector3D *upVec, int16_t scnrPlacementBlockIndex,
		int objectType, const Blam::MapVariant::VariantProperties* variantProperties, unsigned short placementFlags))(0x00582110);
	const auto GetPlayerHoldingObject = (unsigned int(__cdecl*)(int objectIndex))(0x0059BB90);
	const auto GetEditorModeState = (bool(__cdecl *)(unsigned int playerIndex, unsigned int* heldObjectIndex, unsigned int* objectIndexUnderCrosshair))(0x59A6F0);
	const auto GetSandboxGlobals = (SandboxGlobals&(*)())(0x0059BC10);
	const auto ObjectIsPhased = (bool(*)(unsigned int objectIndex))(0x0059A7B0);
	const auto PrintKillFeedText = (void(__cdecl *)(int hudIndex, wchar_t *text, int a3))(0x00A95920);
}