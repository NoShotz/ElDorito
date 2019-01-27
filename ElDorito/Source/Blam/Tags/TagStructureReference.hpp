#pragma once

namespace Blam::Tags
{
	template <typename Type>
	struct TagStructureReference
	{
		Type *Address;
		void *RuntimeAddress;
		void *DefinitionAddress;
	};
	static_assert(sizeof(TagStructureReference<void>) == 0xC);
}