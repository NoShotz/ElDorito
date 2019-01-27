#include "SoundRangeValues.hpp"

namespace Blam::Math {

	// Convert from volume to decibel scale
	inline float ConvertDecibelToVolume(float decibel) {
		return pow(decibel / 20, 10);
	}

	// Convert from decibel to volume scale
	inline float ConvertVolumeToDecibel(float volume) {
		return 20 * log10(volume);
	}

	float SoundRange(int type, float min, float max, float scale) {

		auto vMin = ConvertDecibelToVolume(min);
		auto vMax = ConvertDecibelToVolume(max);
		auto result = max;

		switch(type) {
			case 0:
				return (max - min)*scale + min;
			case 1:
				result = (vMax - vMin) * scale + vMin;
				break;

			case 2:
				if (vMax <= vMin) {
					result = 1.0 - scale;
				}
				else {
					result = scale;
				}
				result = (vMax - vMin) * sqrt(result) + vMin;
				break;

			case 3:
				if (vMax <= vMin) {
					result = scale;
				}
				else {
					result = 1.0 - scale;
				}
				result = (vMax - vMin) * (1.0 - sqrt(result)) + vMin;
				break;

			case 4:
				result = (vMax - vMin) * weirdComputation(scale) + vMin;
				break;

			default:
				return max;
				break;
		}
		return boundVolume(result);
	}

	float boundVolume(float volume) {
		float v1 = 0;
		float v4 = 0;
		float result = 0;

		if (volume < 0.0)
			v1 = 0.0;
		else if (volume > 1.0)
			v1 = 1.0;
		else
			v1 = volume;

		if (volume < 0.0)
			v4 = -64;
		else {
			v4 = 20 * log10(v1);
			if (v4 <= -64)
				v4 = -64;
			else if (v4 > 0)
				v4 = 0;
		}
		return v4;
	}

	float weirdComputation(float volume) {
		float result = 3 * pow(volume, 2) - 2 * pow(volume, 3);
		if (result < 0.0)
			result = 0.0;
		else if (result > 1.0)
			result = 1.0;
		return result;
	}

}