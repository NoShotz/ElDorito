#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Bitmap {
	struct BitmapResource
	{
		int test;
	};
	TAG_STRUCT_SIZE_ASSERT(BitmapResource, 0x4);
}