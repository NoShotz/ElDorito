#pragma once

#include <Blam\Tags\Tags.hpp>
#include "PromotionRule.hpp"
#include "RuntimeTimer.hpp"

namespace Blam::Tags::Sounds
{
	struct Promotion {
		TagBlock<PromotionRule> PromotionsRules;
		TagBlock<RuntimeTimer> RuntimeTimers;
	};
	TAG_STRUCT_SIZE_ASSERT(Promotion, 0x18);
}