#include "Experimental.hpp"
#include "../Patch.hpp"

namespace
{
	struct struc_703;
	bool __fastcall network_window_completion_hook(struc_703 *thisptr, void *unused);
}

namespace Patches::Experimental
{
	void ApplyAll()
	{
		Hook(0x1A8B30, network_window_completion_hook).Apply();
		*(uint32_t*)0x19A71F4 = 7;
	}
}

namespace
{
	struct struc_703
	{
		int field_0;
		int field_4;
		int WindowMin;
		int WindowMax;
		int field_10;
	};
	bool __fastcall network_window_completion_hook(struc_703 *thisptr, void *unused)
	{
		auto client = (uint8_t*)thisptr - 0x14;
		if (thisptr->WindowMin != thisptr->WindowMax)
		{
			if (!*(void**)((uint8_t*)client + 0x30))
			{
				return true;
			}

			return false;
		}

		return true;
	}
}