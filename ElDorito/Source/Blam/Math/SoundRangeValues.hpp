#pragma once
#include <cstdint>
#include <cmath>

namespace Blam::Math {

	float SoundRange(int type, float min, float max, float scale);

	inline float ConvertDecibelToVolume(float decibel);

	inline float ConvertVolumeToDecibel(float volume);

	float boundVolume(float volume);

	float weirdComputation(float volume);
}
