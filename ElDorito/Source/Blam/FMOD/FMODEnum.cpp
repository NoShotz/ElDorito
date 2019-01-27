#include "FMODEnum.hpp"

namespace FMOD {

	inline FMOD_INITFLAGS operator|(FMOD_INITFLAGS a, FMOD_INITFLAGS b)
	{
		return static_cast<FMOD_INITFLAGS>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline FMOD_MODE operator|(FMOD_MODE a, FMOD_MODE b)
	{
		return static_cast<FMOD_MODE>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline FMOD_CHANNELMASK operator|(FMOD_CHANNELMASK a, FMOD_CHANNELMASK b)
	{
		return static_cast<FMOD_CHANNELMASK>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline FMOD_TIMEUNIT operator|(FMOD_TIMEUNIT a, FMOD_TIMEUNIT b) 
	{
		return static_cast<FMOD_TIMEUNIT>(static_cast<int>(a) | static_cast<int>(b));
	}
}

namespace Studio {

	inline FMOD_STUDIO_INITFLAGS operator|(FMOD_STUDIO_INITFLAGS a, FMOD_STUDIO_INITFLAGS b)
	{
		return static_cast<FMOD_STUDIO_INITFLAGS>(static_cast<int>(a) | static_cast<int>(b));
	}
}