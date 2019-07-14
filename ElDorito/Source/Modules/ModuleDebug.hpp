#pragma once
#include "ModuleBase.hpp"

namespace Modules
{
	class ModuleDebug : public Utils::Singleton<ModuleDebug>, public Modules::ModuleBase
	{
	public:
		Command* VarMemcpySrc;
		Command* VarMemcpyDst;
		Command* VarMemsetDst;
		Command *VarPrintHsEvaluations;

		Command *VarDirtyDiskContinueType;

		ModuleDebug();
	};
}