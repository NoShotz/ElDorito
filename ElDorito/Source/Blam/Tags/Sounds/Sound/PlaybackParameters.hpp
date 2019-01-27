#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>

namespace Blam::Tags::Sounds {

	struct PlaybackParameters {
		uint32_t PlaybackParameterFlags;
		float DistanceA;
		float DistanceB;
		float DistanceC;
		float DistanceD;
		float SkipFraction;
		float MaximumBendPerSecond;
		float GainBase;
		float GainVariance;
		Math::Bounds<int16_t> RandomPitch;
		Math::Bounds<float> ConeAngle;
		float OuterConeGain;
		float OverrideFlags;
		float Azimuth;
		float PositionalGain;
		float FirstPersonGain;
	};
	TAG_STRUCT_SIZE_ASSERT(PlaybackParameters, 0x44);
	
}