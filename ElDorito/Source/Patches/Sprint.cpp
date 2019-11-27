#include "Sprint.hpp"
#include "../Patch.hpp"
#include "../ElDorito.hpp"
#include "../Blam/BlamTypes.hpp"
#include "../Blam/Memory/TlsData.hpp"

namespace
{
	bool sprintEnabled = true;
	Patch disableSprintPatch(0x13E26B, { 0x90, 0xE9 });
	Patch unlimitedSprintPatch(0x13E5D1, { 0x00 });
}

namespace Patches::Sprint
{
	void Enable(bool enabled)
	{
		sprintEnabled = enabled;
		if (enabled)
			disableSprintPatch.Reset();
		else
			disableSprintPatch.Apply();
	}

	void SetUnlimited(bool unlimited)
	{
		if (unlimited)
			unlimitedSprintPatch.Apply();
		else
			unlimitedSprintPatch.Reset();
	}

	void Tick()
	{
		// Show/hide the sprint meter
		Blam::Memory::chud_player_hud_elements *persistentUserDataChud = ElDorito::GetMainTls(GameGlobals::PersistentUserDataChud::TLSOffset)[0](GameGlobals::PersistentUserDataChud::HUDElementsOffset);
		if (persistentUserDataChud)
			persistentUserDataChud->stamina = sprintEnabled;
	}
}
