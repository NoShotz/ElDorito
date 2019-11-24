#include "ScreenLayer.hpp"
#include "../../Patches/Input.hpp"
#include "../../Patches/Ui.hpp"
#include "../../Modules/ModuleInput.hpp"
#include "../../Modules/ModuleSettings.hpp"

namespace
{
	void OnGameInputUpdated();
}

namespace Web::Ui::WebSettings
{
	void Init()
	{
		Patches::Input::RegisterDefaultInputHandler(OnGameInputUpdated);
	}

	void Show()
	{
		ScreenLayer::Show("settings", "{}");
	}
}

namespace
{
	const auto UI_ScreenManager_GetScreenWidget = (void* (__thiscall*)(void* thisptr, int a2, uint32_t nameId))(0x00AAB550);

	void OnGameInputUpdated()
	{
		if (Modules::ModuleSettings::Instance().VarGamepadEnabled->ValueInt == 1)
		{
			if (Blam::Input::GetActionState(Blam::Input::eGameActionUiStart)->Ticks == 1 && strcmp((char*)Pointer(0x22AB018)(0x1A4), "mainmenu") == 0)
				Web::Ui::WebSettings::Show();
		}

		if (GetKeyTicks(Blam::Input::eKeyCodeHome, Blam::Input::eInputTypeUi) && strcmp((char*)Pointer(0x22AB018)(0x1A4), "mainmenu") == 0)
		{
			auto screenManager = (void*)0x05260F34;
			if (!UI_ScreenManager_GetScreenWidget(screenManager, 4, 0x10084))
			{
				Patches::Ui::ShowDialog(0x10084, 0, 4, 0x1000C);
			}
		}
			
	}
}
