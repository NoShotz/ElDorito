#pragma once
#include "../../Text/StringID.hpp"
#include "../TagBlock.hpp"
#include "../TagFunction.hpp"
#include "../TagMapping.hpp"
#include "../TagReference.hpp"

namespace Blam::Tags::Shaders
{
	struct RenderMethodUnknownBlock1
	{
		short Unknown;
	};
	static_assert(sizeof(RenderMethodUnknownBlock1) == 0x2);

	struct RenderMethodFunction
	{
		long Unknown1;
		Text::StringID Name;
		long Unknown2;
		long Unknown3;
		TagFunction Function;
	};
	static_assert(sizeof(RenderMethodFunction) == 0x24);

	struct RenderMethodImportData
	{
		Text::StringID MaterialType;
		long Unknown;
		TagReference Bitmap;
		unsigned long Unknown2;
		long Unknown3;
		short Unknown4;
		short Unknown5;
		short Unknown6;
		short Unknown7;
		short Unknown8;
		short Unknown9;
		unsigned long Unknown10;
		TagBlock<RenderMethodFunction> Functions;
	};
	static_assert(sizeof(RenderMethodImportData) == 0x3C);

	enum class RenderMethodShaderMapFlags : unsigned char
	{
		None,
		Bit0 = 1 << 0,
		Bit1 = 1 << 1,
		Bit2 = 1 << 2,
		Bit3 = 1 << 3,
		Bit4 = 1 << 4,
		Bit5 = 1 << 5,
		Bit6 = 1 << 6,
		Bit7 = 1 << 7
	};
	static_assert(sizeof(RenderMethodShaderMapFlags) == 0x1);

	struct RenderMethodShaderMap
	{
		TagReference Bitmap;
		char Unknown;
		char BitmapIndex;
		char Unknown2;
		RenderMethodShaderMapFlags BitmapFlags : 8;
		char UnknownBitmapIndexEnable;
		char UvArgumentIndex;
		char Unknown3;
		char Unknown4;
	};
	static_assert(sizeof(RenderMethodShaderMap) == 0x18);

	struct RenderMethodArgument
	{
		float Values[4];
	};
	static_assert(sizeof(RenderMethodArgument) == 0x10);

	struct RenderMethodUnknownBlock2
	{
		unsigned long Unknown;
	};
	static_assert(sizeof(RenderMethodUnknownBlock2) == 0x4);

	struct RenderMethodDrawMode
	{
		unsigned short DataHandle;
	};
	static_assert(sizeof(RenderMethodDrawMode) == 0x2);

	struct RenderMethodUnknownBlock3
	{
		short DataHandleSampler;
		short DataHandleUnknown;
		short DataHandleVector;
	};
	static_assert(sizeof(RenderMethodUnknownBlock3) == 0x6);

	struct RenderMethodArgumentMapping
	{
		short RegisterIndex;
		unsigned char FunctionIndex;
		unsigned char ArgumentIndex;
	};
	static_assert(sizeof(RenderMethodArgumentMapping) == 0x4);

	struct RenderMethodShaderProperties
	{
		TagReference Template;
		TagBlock<RenderMethodShaderMap> ShaderMaps;
		TagBlock<RenderMethodArgument> Arguments;
		TagBlock<RenderMethodUnknownBlock2> Unknown1;
		unsigned long Unknown2;
		TagBlock<RenderMethodDrawMode> DrawModes;
		TagBlock<RenderMethodUnknownBlock3> Unknown3;
		TagBlock<RenderMethodArgumentMapping> ArgumentMappings;
		TagBlock<RenderMethodFunction> Functions;
		long BitmapTransparency;
		long Unknown7;
		long Unknown8;
		short Unknown9;
		short Unknown10;
		short Unknown11;
		short Unknown12;
		short Unknown13;
		short Unknown14;
		short Unknown15;
		short Unknown16;
	};
	static_assert(sizeof(RenderMethodShaderProperties) == 0x84);

	struct RenderMethod
	{
		TagReference BaseRenderMethod;
		TagBlock<RenderMethodUnknownBlock1> Unknown1;
		TagBlock<RenderMethodImportData> ImportData;
		TagBlock<RenderMethodShaderProperties> ShaderProperties;
		TagMappingVariableType InputVariable;
		TagMappingVariableType RangeVariable;
		TagMappingOutputModifier OutputModifier;
		TagMappingVariableType OutputModifierInput;
		float RuntimeMConstantValue;
		long Unknown2; // usually -1
	};
	static_assert(sizeof(RenderMethod) == 0x40);
}