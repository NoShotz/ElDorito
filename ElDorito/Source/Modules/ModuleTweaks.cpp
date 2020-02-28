#include "ModuleTweaks.hpp"
#include "../Patches/Ui.hpp"
#include "../Patches/Tweaks.hpp"

namespace
{
	bool VariableFlatHUDUpdated(const std::vector<std::string>& arguments, std::string& returnInfo)
	{
		Patches::Ui::UpdateHUDDistortion();
		return true;
	}

	bool VariableChudGlobalsIndexUpdated(const std::vector<std::string>& arguments, std::string& returnInfo)
	{
		Patches::Ui::chudIndex = Modules::ModuleTweaks::Instance().VarChudGlobalsIndex->ValueInt;
		Patches::Tweaks::UpdateUnitHUD();
		return true;
	}
}

namespace Modules
{
	ModuleTweaks::ModuleTweaks() : ModuleBase("Tweaks")
	{
		VarIntelBloomPatch = AddVariableInt("IntelBloomPatch", "intelbloompatch", "Fixes excessive bloom when using Intel integrated graphics", eCommandFlagsArchived, 0);
		VarIntelBloomPatch->ValueIntMin = 0;
		VarIntelBloomPatch->ValueIntMax = 1;

		VarAggressiveAudioDiscarding = AddVariableInt("AggressiveAudioDiscarding", "aggressiveaudiodiscarding", "Discard sounds more aggressively to prevent audio latency. This is a workaround, not a fix.", eCommandFlagsArchived, 0);
		VarAggressiveAudioDiscarding->ValueIntMin = 0;
		VarAggressiveAudioDiscarding->ValueIntMax = 1;

		VarDisableReactorFog = AddVariableInt("DisableReactorFog", "disablereactorfog", "Disable the fog effects around the moving platforms on the Reactor map to increase performance.", eCommandFlagsArchived, 0);
		VarDisableReactorFog->ValueIntMin = 0;
		VarDisableReactorFog->ValueIntMax = 1;

		VarDisableWeaponOutline = AddVariableInt("DisableWeaponOutline", "disableweaponoutline", "Disables the outline effect on weapons and equipment.", eCommandFlagsArchived, 0);
		VarDisableWeaponOutline->ValueIntMin = 0;
		VarDisableWeaponOutline->ValueIntMax = 1;

		VarDisableHitMarkers = AddVariableInt("DisableHitMarkers", "disablehitmarkers", "Disables weapon hitmarkers.", eCommandFlagsArchived, 0);
		VarDisableHitMarkers->ValueIntMin = 0;
		VarDisableHitMarkers->ValueIntMax = 1;

		VarReachStyleFrags = AddVariableInt("ReachStyleFrags", "reachstylefrags", "Adds a Halo: Reach style trail effect to frag grenades.", eCommandFlagsArchived, 0);
		VarReachStyleFrags->ValueIntMin = 0;
		VarReachStyleFrags->ValueIntMax = 1;

		VarFlatHUD = AddVariableInt("FlatHUD", "flathud", "Removes distortion from the HUD.", eCommandFlagsArchived, 0, VariableFlatHUDUpdated);
		VarFlatHUD->ValueIntMin = 0;
		VarFlatHUD->ValueIntMax = 1;

		VarChudGlobalsIndex = AddVariableInt("ChudGlobalsIndex", "chudglobalsindex", "Switches HUD globals to the specified index.", eCommandFlagsArchived, 0, VariableChudGlobalsIndexUpdated);
		VarChudGlobalsIndex->ValueIntMin = 0;

		VarSinglethreaded = AddVariableInt("Singlethreaded", "singlethreaded", "Enables singlethreaded mode.", eCommandFlagsArchived, 0);
		VarSinglethreaded->ValueIntMin = 0;
		VarSinglethreaded->ValueIntMax = 1;

		VarDisableMetagame = AddVariableInt("DisableMetagame", "disable_metagame", "Disables the campaign metagame.", eCommandFlagsArchived, 1);
		VarDisableMetagame->ValueIntMin = 0;
		VarDisableMetagame->ValueIntMax = 1;
        
		VarDisableContrails = AddVariableInt("DisableContrails", "disable_contrails", "Disables the contrail rendering system.", eCommandFlagsArchived, 0);
		VarDisableContrails->ValueIntMin = 0;
		VarDisableContrails->ValueIntMax = 1;

	}
}