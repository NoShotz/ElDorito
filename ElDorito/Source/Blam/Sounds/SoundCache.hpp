#pragma once
#include "..\Tags\Sounds\Sound\Sound.hpp"
#include "..\Tags\Sounds\SoundClasses\SoundClasses.hpp"
#include "..\Math\Random.hpp"
#include <math.h>
#include "..\Memory\Align.hpp"
#include "..\Sounds\SoundDatum.hpp"
#include "..\Memory\DatumHandle.hpp"
#include "SoundGlobals.hpp"



namespace Blam::SoundCache {

	using namespace Blam::Tags::Sounds;

	//0x65FCB0
	int32_t AllocateSound(int32_t SoundTagIndex, PermutationChunk *Chunk, uint32_t a3);

	//0x6602B0
	int32_t AllocateSoundInArray(int32_t SoundTagIndex, PermutationChunk *Chunk, int8_t *a3);
}