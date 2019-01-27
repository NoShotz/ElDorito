#pragma once

#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	struct PlatformCodec {
		int8_t Unknown3;
		int8_t LoadMode;
		int8_t Encoding;
		int8_t Compression;
	};
	TAG_STRUCT_SIZE_ASSERT(PlatformCodec, 0x4);
}