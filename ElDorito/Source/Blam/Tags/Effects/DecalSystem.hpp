#pragma once
#include "../../Math/Bounds.hpp"
#include "../../Math/RealPoint2D.hpp"
#include "../../Text/StringID.hpp"
#include "../Shaders/RenderMethod.hpp"
#include "../TagBlock.hpp"

namespace Blam::Tags::Effects
{
	enum class DecalSystemFlags : long
	{
		None = 0,
		Bit0 = 1 << 0,
		Bit1 = 1 << 1,
		Bit2 = 1 << 2,
		Bit3 = 1 << 3,
		Bit4 = 1 << 4,
		Bit5 = 1 << 5,
		Bit6 = 1 << 6,
		Bit7 = 1 << 7,
		Bit8 = 1 << 8,
		Bit9 = 1 << 9,
		Bit10 = 1 << 10,
		Bit11 = 1 << 11,
		Bit12 = 1 << 12,
		Bit13 = 1 << 13,
		Bit14 = 1 << 14,
		Bit15 = 1 << 15,
		Bit16 = 1 << 16,
		Bit17 = 1 << 17,
		Bit18 = 1 << 18,
		Bit19 = 1 << 19,
		Bit20 = 1 << 20,
		Bit21 = 1 << 21,
		Bit22 = 1 << 22,
		Bit23 = 1 << 23,
		Bit24 = 1 << 24,
		Bit25 = 1 << 25,
		Bit26 = 1 << 26,
		Bit27 = 1 << 27,
		Bit28 = 1 << 28,
		Bit29 = 1 << 29,
		Bit30 = 1 << 30,
		Bit31 = 1 << 31
	};
	static_assert(sizeof(DecalSystemFlags) == 0x4);

	enum class DecalDefinitionFlags : long
	{
		None = 0,
		Bit0 = 1 << 0,
		Bit1 = 1 << 1,
		Bit2 = 1 << 2,
		Bit3 = 1 << 3,
		Bit4 = 1 << 4,
		Bit5 = 1 << 5,
		Bit6 = 1 << 6,
		Bit7 = 1 << 7,
		Bit8 = 1 << 8,
		Bit9 = 1 << 9,
		Bit10 = 1 << 10,
		Bit11 = 1 << 11,
		Bit12 = 1 << 12,
		Bit13 = 1 << 13,
		Bit14 = 1 << 14,
		Bit15 = 1 << 15,
		Bit16 = 1 << 16,
		Bit17 = 1 << 17,
		Bit18 = 1 << 18,
		Bit19 = 1 << 19,
		Bit20 = 1 << 20,
		Bit21 = 1 << 21,
		Bit22 = 1 << 22,
		Bit23 = 1 << 23,
		Bit24 = 1 << 24,
		Bit25 = 1 << 25,
		Bit26 = 1 << 26,
		Bit27 = 1 << 27,
		Bit28 = 1 << 28,
		Bit29 = 1 << 29,
		Bit30 = 1 << 30,
		Bit31 = 1 << 31
	};
	static_assert(sizeof(DecalDefinitionFlags) == 0x4);

	struct DecalDefinition
	{
		Text::StringID DecalName;
		DecalDefinitionFlags Flags : 32;
		Shaders::RenderMethod RenderMethod;
		Math::Bounds<float> Radius;
		Math::Bounds<float> DecayTime;
		Math::Bounds<float> Lifespan;
		float ClampAngle;
		float CullAngle;
		int Unknown;
		float DepthBias;
		float RuntimeBitmapAspect;
	};
	static_assert(sizeof(DecalDefinition) == 0x74);

	struct DecalSystem
	{
		DecalSystemFlags Flags : 32;
		short RingBufferSize;
		short RingBufferSizeSinglePlayer;
		float MaterialShaderFadeTime;
		Math::RealPoint2D DecalScaleOverride;
		Tags::TagBlock<DecalDefinition> Decal;
		float RuntimeMaxRadius;
	};
	static_assert(sizeof(DecalSystem) == 0x24);
}