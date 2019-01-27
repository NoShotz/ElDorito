#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Bitmap {
	struct Image
	{
		int test;
	};
	TAG_STRUCT_SIZE_ASSERT(Image, 0x4);
}