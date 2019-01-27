#pragma once
#include "TagFunction.hpp"

namespace Blam::Tags
{
	enum class TagMappingVariableType : char
	{
		ParticleAge,
		EmitterAge,
		ParticleRandom,
		EmitterRandom,
		ParticleRandom1,
		ParticleRandom2,
		ParticleRandom3,
		ParticleRandom4,
		EmitterRandom1,
		EmitterRandom2,
		EmitterTime,
		SystemLod,
		GameTime,
		EffectAScale,
		EffectBScale,
		PhysicsRotation,
		LocationRandom,
		DistanceFromEmitter,
		ParticleSimulationA,
		ParticleSimulationB,
		ParticleVelocity,
		Invalid
	};
	static_assert(sizeof(TagMappingVariableType) == 0x1);

	enum class TagMappingOutputModifier : char
	{
		None,
		Plus,
		Times
	};
	static_assert(sizeof(TagMappingOutputModifier) == 0x1);
	
	enum class TagMappingForceFlags : unsigned char
	{
		None,
		ForceConstant = 1 << 0
	};
	static_assert(sizeof(TagMappingForceFlags) == 0x1);

	struct TagMapping
	{
		TagMappingVariableType InputVariable;
		TagMappingVariableType RangeVariable;
		TagMappingOutputModifier OutputModifier;
		TagMappingVariableType OutputModifierInput;
		TagFunction Function;
		float RuntimeMConstantValue;
		unsigned char RuntimeMFlags;
		char : 8;
		short : 16;
	};
	static_assert(sizeof(TagMapping) == 0x20);
}