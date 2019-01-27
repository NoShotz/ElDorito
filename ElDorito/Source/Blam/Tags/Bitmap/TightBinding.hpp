#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Bitmap {
	struct TightBinding
	{
		float U;
		float V;
	};
	TAG_STRUCT_SIZE_ASSERT(TightBinding, 0x8);
}