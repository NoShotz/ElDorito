#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Bitmap {
	struct Sprite
	{
		int16_t Bitmapindex;
		int8_t Padding[6];
		float Left;
		float Right;
		float Top;
		float Bottom;
		float RegistrationPointX;
		float RegistrationPointY;
		
	};
	TAG_STRUCT_SIZE_ASSERT(Sprite, 0x20);
}
