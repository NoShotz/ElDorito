#pragma once
#include <Blam\Tags\Tags.hpp>

namespace Blam::Tags::Sounds
{
	enum class OutputEffect : int16_t {
		None,
		OutputFrontSpeakers,
		OutputRearSpeakers,
		OutputCenterSpeakers
	};
}