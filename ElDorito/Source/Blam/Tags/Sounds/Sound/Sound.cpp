#include "Sound.hpp"

namespace Blam::Tags::Sounds
{
	Scale* GetScale(Sound* sound) {
		return &sound->Scale;
	}

	PlaybackParameters* GetPlaybackParameters(Sound* sound) {
		return &sound->PlaybackParameters;
	}

	SampleRate GetSampleRate(Sound* sound) {
		return sound->SampleRate;
	}

	PitchRange* GetPitchRange(Sound* sound, int32_t index) {
		return &sound->PitchRanges[index];
	}

	int32_t GetPitchRangeCount(Sound* sound) {
		return sound->PitchRanges.Count;
	}

	Permutation* GetPermutation(PitchRange* pitchRange, int32_t index) {
		return &pitchRange->Permutations[index];
	}

	PermutationChunk* GetPermutationChunk(Permutation* permutation, int32_t index) {
		return &permutation->PermutationChunks[index];
	}

	int32_t GetPermutationCount(PitchRange* pitchRange) {
		return pitchRange->Permutations.Count;
	}

	int32_t GetPermutationChunkCount(Permutation* permutation) {
		return permutation->PermutationChunks.Count;
	}

	int8_t GetCompression(Sound* sound) {
		return sound->PlatformCodec.Compression;
	}

	int8_t GetLoadMode(Sound* sound) {
		return sound->PlatformCodec.LoadMode;
	}

	int8_t GetEncoding(Sound* sound) {
		return sound->PlatformCodec.Encoding;
	}

	int32_t GetNextPermutationChunkIndex(Permutation* permutation, int32_t currentIndex) {
		if (permutation && currentIndex < permutation->PermutationChunks.Count - 1)
			return currentIndex + 1;
		else
			return -1;
	}

	Math::Bounds<int16_t>* GetBendBounds(PitchRange* pitchRange) {
		return &pitchRange->Bend;
	}

}