#pragma once
#include "../../Tags.hpp"
#include "ClassProperty.hpp"
#include "SoundClassEnum.hpp"

namespace Blam::Tags::Sounds
{
	struct Classes : TagGroup<'sncl'>
	{
		TagBlock<ClassProperty> ClassProperties;
		uint32_t Unknown;
	};
	TAG_STRUCT_SIZE_ASSERT(Classes, 0x10);

	ClassProperty* GetClassProperty(Classes* classes, SoundClass soundClass);
}
