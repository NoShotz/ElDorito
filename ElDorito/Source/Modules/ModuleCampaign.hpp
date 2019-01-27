#pragma once

#include "ModuleBase.hpp"

namespace Modules
{
	class ModuleCampaign : public Utils::Singleton<ModuleCampaign>, public ModuleBase
	{
	public:
		Command* VarFrameLimit;
		Command* VarDifficultyLevel;
		Command* VarInsertionPoint;
		Command* VarMetagameScoringOption;
		Command* VarMetagameEnabled;
		Command* VarSurvivalModeEnabled;

		ModuleCampaign();
	};
}