#pragma once
#include "../../Tags.hpp"

namespace Blam::Tags::Sounds {
	enum class CacheMissMode : int8_t
	{
		Discard,
		Postpone
	};
}