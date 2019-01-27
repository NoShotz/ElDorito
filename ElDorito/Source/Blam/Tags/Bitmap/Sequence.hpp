#include <Blam\Tags\Tags.hpp>

#include <Blam\Tags\Bitmap\Sprite.hpp>

namespace Blam::Tags::Bitmap {
	struct Sequence
	{
		char Name[0x20];
		int16_t FirstBitmapIndex;
		int16_t BitmapCount;
		char Padding[0x10];
		TagBlock<Sprite> Sprites;
	};
	TAG_STRUCT_SIZE_ASSERT(Sequence, 0x40);
}
