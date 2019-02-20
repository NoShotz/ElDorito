#pragma once
#include <cstdint>

#include "../BlamTypes.hpp"

namespace Blam
{
	struct Preferences;

	inline Preferences *GetPreferences()
	{
		return *(Preferences **)0x022C0128;
	}

	struct Preferences
	{
		struct ScreenResolution
		{
			int32_t Width, Height;
		};

		struct GamemodeData
		{
			struct CampaignData
			{
				uint8_t Unknown0;
				uint8_t Unknown1;
				uint8_t Unknown2;
				uint8_t Unknown3;
				uint32_t CampaignId;
				uint32_t MapId;
				uint16_t CampaignInsertionPoint;
				uint16_t UnknownE;
				uint32_t CampaignDifficultyLevel;
				uint32_t CampaignMetagameScoringOption;
				uint32_t CampaignSkullsPrimary;
				uint32_t CampaignSkullsSecondary;
				char Unknown20[0x78];
				char Unknown98[0x80];
				char Unknown118[0x80];
			};
			static_assert(sizeof(CampaignData) == 0x198);
			struct MatchMakingData
			{
				uint8_t Unknown0;
				uint8_t Unknown1;
				uint16_t Unknown2;
				uint8_t Unknown4;
				uint8_t Unknown5;
				uint16_t MatchMakingHopper;
			};
			static_assert(sizeof(MatchMakingData) == 0x8);
			struct MultiplayerData
			{
				uint8_t Unknown0;
				uint8_t Unknown1;
				uint8_t Unknown2;
				uint8_t Unknown3;
				uint8_t GameVariant[0x264];
				uint8_t Unknown4[0x210];
				uint8_t MapVariant[0xE090];
				uint8_t UnknownE508[0x210];
			};
			static_assert(sizeof(MultiplayerData) == 0xE718);
			struct ForgeData
			{
				uint8_t Unknown0;
				uint8_t Unknown1;
				uint8_t Unknown2;
				uint8_t Unknown3;
				uint32_t Unknown4;
				uint8_t MapVariant[0xE090];
				uint8_t UnknownE098[0x210];
			};
			static_assert(sizeof(ForgeData) == 0xE2A8);
			struct TheaterData
			{
				struct SavedFilmDescription
				{
					uint32_t CampaignId;
					uint32_t MapId;

					// This seems like it'd be correct going by `CampaignData` but I've nothing to confirm it
					uint16_t CampaignInsertionPoint;
					uint16_t UnknownE;
					uint32_t CampaignDifficultyLevel;
					uint32_t CampaignMetagameScoringOption;
					uint32_t CampaignSkullsPrimary;
					uint32_t CampaignSkullsSecondary;
					uint8_t Unknown16[0x1FA];

					// Leaving these here incase the above is incorrect
					//uint8_t Unknown8[8];
					//uint32_t Unknown10;
					//uint16_t Unknown14;
					//uint8_t Unknown16[0x1FE];

					uint16_t Unknown214;
					uint8_t Unknown216[0x42];
					uint8_t Unknown258[0xBA];
					uint32_t Unknown316;
					uint32_t Unknown31A;
				};
				static_assert(sizeof(SavedFilmDescription) == 0x31C);

				uint8_t Unknown0;
				uint8_t Unknown1;
				uint8_t Unknown2;
				uint8_t Unknown3;
				uint8_t Unknown4[0x10];
				SavedFilmDescription SavedFilmDescription;
				Blam::GameOptions GameOptions;
				uint8_t Unknown24E78[8];
			};
			static_assert(sizeof(TheaterData) == 0x24E80);

			CampaignData Campaign;
			CampaignData FireFight; // FireFight seems to be keeping to the same struct as Campaign, I'll use that instead
			MatchMakingData MatchMaking;
			MultiplayerData Multiplayer;
			ForgeData Forge;
			TheaterData Theater;
		};
		static_assert(sizeof(GamemodeData) == 0x41B78);

		struct SoundsControls
		{
			uint32_t MasterVolume;
			uint32_t SfxVolume;
			uint32_t MusicVolume;
			uint32_t VoiceVolume;
			uint32_t VoiceChatControl;
			uint32_t VoiceChatVolume;
		};

		uint8_t Unknown00;
		uint8_t IsDirty;
		uint8_t Unknown[0x1E];
		uint32_t Unknown20;
		uint32_t Language;
		uint32_t Unknown28;
		ScreenResolution ScreenResolutionList;
		uint32_t MinorVersion;
		uint32_t Unknown38;
		uint32_t Unknown3C;
		uint32_t LastLoadedLobby; // String Id
		uint32_t Unknown44;
		GamemodeData GamemodeData;
		Blam::NetworkMode LastNetworkMode;
		uint32_t Unknown41BC4;
		uint32_t DefaultVideoSettings;
		uint8_t Fullscreen;
		uint32_t Unknown41BD0;
		uint32_t Contrast;
		uint32_t Brightness;
		uint32_t Unknown41BDC;
		ScreenResolution ScreenResolution;
		uint32_t Unknown41BE8;
		uint32_t Unknown41BEC;
		uint32_t TextureResolution;
		uint32_t ShadowQuality;
		uint32_t TextureFilteringQuality;
		uint32_t LightingQuality;
		uint32_t EffectsQuality;
		uint32_t DetailsQuality;
		uint32_t PostprocessingQuality;
		uint8_t MotionBlur;
		uint8_t VSync;
		uint8_t Antialiasing;
		uint8_t Unknown41C0F;
		uint8_t HideWatermark;
		uint32_t DisplaySubtitles;
		uint32_t DisplayAdapter;
		uint32_t Unknown41C1C;
		uint32_t Unknown41C20;
		uint32_t Unknown41C24;
		uint32_t Unknown41C28;
		uint32_t Unknown41C2C;
		uint32_t Unknown41C30;
		uint32_t Unknown41C34;
		uint32_t Unknown41C38;
		uint32_t Unknown41C3C;
		uint32_t Unknown41C40;
		uint32_t Unknown41C44;
		uint32_t Unknown41C48;
		uint32_t Unknown41C4C;
		SoundsControls SoundsControls;
		uint8_t ToggleCrouch;
		uint8_t HUDShake;
		uint8_t Unknown41C6A;
		uint8_t Unknown41C6B;
		uint32_t TeamColor;
		float CameraFov;
		uint32_t ControlsMethod;
		uint32_t MouseSensitivityVertical;
		uint32_t MouseSensitivityHorizontal;
		uint32_t MouseSensitivityVehicleVertical;
		uint32_t MouseSensitivityVehicleHorizontal;
		uint32_t MouseAcceleration;
		uint8_t MouseFilter;
		uint8_t InvertMouse;
		uint8_t Unknown41C8E;
		uint8_t Unknown41C8F;
		uint32_t Unknown41C90;
		uint8_t Bindings[0x17c];
		uint8_t Unknown41E10[0x1F0];
	};
	static_assert(sizeof(Preferences) == 0x42000);
}