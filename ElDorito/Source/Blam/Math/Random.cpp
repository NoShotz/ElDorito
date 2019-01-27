#include "Random.hpp"

namespace Blam::Math {

	uint32_t random_seed(uint32_t* seed)
	{
		uint32_t new_seed = 1664525 * *seed + 1013904223;
		*seed = new_seed;
		return (new_seed >> 16);
	};

	uint32_t random_seed_range(uint32_t* seed, int16_t min, int16_t max)
	{
		uint32_t value = random_seed(seed);
		return min + ((value*(max - min)) >> 16);
	};

	double real_random_seed(uint32_t* seed)
	{
		return ((double)(random_seed(seed)) / 65535.0);
	};

	double real_random_seed_range(uint32_t* seed, float min, float max)
	{
		return (min + (max - min)*real_random_seed(seed));
	};

	int32_t* get_random_seed()
	{
		return reinterpret_cast<int32_t*>(0x400000 + 0x238ED14);
	};

}
