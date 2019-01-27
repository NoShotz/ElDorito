#pragma once
#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	enum class ImportType : int8_t {
		Unknown,
		SingleShot,
		SingleLayer,
		MultiLayer
	};
}
