#include "SoundCache.hpp"

namespace Blam::SoundCache {

	enum SoundAllocationFlags : uint32_t {
		NONE = 0x0,
		FLAG1 = 0x1 << 0,
		FLAG2 = 0x1 << 1,	// Has valid runtime index
		FLAG3 = 0x1 << 2,   // Has incremented count in data array
		FLAG4 = 0x1 << 3
	};


	int32_t AllocateSound(int32_t SoundTagIndex, PermutationChunk *Chunk, uint32_t a3) {

		int32_t return_flags = NONE;

		// cryptic code to keep track of some kind of information

		int8_t v4 = (int8_t) ((a3 >> 1) & 0xFFFFFF01);


		if (Chunk->Offset != -1 && Chunk->RuntimeIndex == -1 && SoundTagIndex != -1 && a3 & 1) {
			AllocateSoundInArray(SoundTagIndex, Chunk, (int8_t*)&a3 + 3);
			//LOBYTE(v4) = v8; some black magic going on with the stack and a3. Not sure of the purpose.
		}

		if (Chunk->RuntimeIndex != -1) {
			return_flags = FLAG2;
			if (v4) {
				//++globalXboxSounds[Chunk->RuntimeIndex].NumberTimesRequested;
				return_flags |= FLAG3;
			}
		}

		if (!(return_flags & (FLAG4 | FLAG3)) && Chunk->RuntimeIndex != -1) {
			return_flags |= FLAG1;
		}
		
		if ( HIBYTE(a3)) {
			return_flags |= FLAG4;
		}
			
		return return_flags;
	}

	int32_t AllocateSoundInArray(int32_t SoundTagIndex, PermutationChunk *Chunk, int8_t *a3) {
		//This is only used to signal that a allocation has been made
		*a3 = 0;

		int32_t result = 0; //sub_667650(). Some byte value in memory. Probably to indicate if array is full

		if (result) {

			// Why bother doing that? It<s in the decompiled code but doesn't seem to be used anywhere.
			int chunkSize = Memory::Align16Bits(0x3FFFFFF & Chunk->EncodedSize);

			//Blam::DatumHandle handle = AllocateDatum<Blam::XboxSoundDatum>(globalXboxSounds);

			//Chunk->RuntimeIndex = handle.Index;
			//result = SoundTagIndex;
			//globalXboxSounds[handle.Index].Chunk = Chunk;
			//globalXboxSounds[handle.Index].NumberTimesRequested = 0;
			//globalXboxSounds[handle.Index].SoundTagIndex = SoundTagIndex;
		}

		return result;
	}
}