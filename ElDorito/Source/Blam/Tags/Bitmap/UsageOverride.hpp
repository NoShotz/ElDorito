#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Bitmap {
	struct UsageOverride
	{
		float SourceGamma;
		int32_t BitmapCurveEnum;
		int32_t Unknown8;
		int32_t UnknownC;
		int32_t Unknown10;
		int32_t Unknown14;
		int32_t Unknown18;
		int32_t Unknown1C;
		int32_t Unknown20;
		int32_t Unknown24;
	};
	TAG_STRUCT_SIZE_ASSERT(UsageOverride, 0x28);
}