#pragma once
#include <cstdint>

namespace Blam::Math {

	uint32_t random_seed(uint32_t* seed);
	uint32_t random_seed_range(uint32_t* seed, int16_t min, int16_t max);
	double real_random_seed(uint32_t* seed);
	double real_random_seed_range(uint32_t* seed, float min, float max);
	int32_t* get_random_seed();

}
