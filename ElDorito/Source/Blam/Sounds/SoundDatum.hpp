#pragma once
#include <stdint.h>
#include "../Tags/Sounds/Sound/Sound.hpp"
#include "../BlamData.hpp"


//using namespace Blam::Tags::Sounds;

namespace Blam {

	using namespace Blam::Tags::Sounds;

	struct XboxSoundDatum : DatumBase{
		int16_t NumberTimesRequested;
		int32_t SoundTagIndex;
		PermutationChunk* Chunk;
	};
	static_assert(sizeof(XboxSoundDatum) == 0xC, "Invalid XboxSoundDatum size");

	struct TrackDatum {
		DatumHandle LoopSoundSourcesHandle;
		int32_t field_4;
		int32_t field_8;
		int8_t SoundEnumType1;
		int8_t SoundEnumType2;
		int16_t field_E;
		int32_t field_10;
		int32_t field_14;
		int32_t field_18;
		int32_t field_1C;
		int32_t field_20;
	};
	static_assert(sizeof(TrackDatum) == 0x24, "Invalid TrackDatum size");

	struct SoundSourceDatum : DatumBase {
		int16_t field_2;				// 0x2 means looping
		int32_t Flags;					// 0x01 update g_xbox_sound chunk | 0x40 not allocated in g_xbox_sound | 0x8 valid g_xbox_sound
		int16_t field_8;				// 0x1 means looping
		int16_t field_A;
		int32_t field_C;
		int32_t SoundTagIndex;
		DatumHandle LoopingSoundDatumHandle;
		void*	CallBackAddress;				// seems to point to a function call see 00664D26

		// Block of size 0x4C, copied into SoundSource sometimes
		struct {
			int16_t Flags2;
			int16_t field_1E;				// Some flags
			float Pitch_field_20;			// Used in a math function as the input for the min and max bounds in sound gain
			float Volume_field_24;
			float Position_X;
			float Position_Y;
			float Position_Z;
			int32_t field_34;
			int32_t field_38;
			int32_t field_3C;
			int32_t field_40;
			float field_44_X;
			float field_44_Y;
			float field_44_Z;
			int32_t field_50;
			int32_t field_54;
			int32_t field_58;
			float field_5C;
			int32_t field_60;
			int32_t field_64;
		};

		int32_t PlaybackControllerHandle;
		int16_t LoopingSoundTrackIndex;
		int16_t field_6E;
		int32_t field_70;
		int32_t field_74;
		int32_t SoundSourceIndex1;
		int32_t SoundSourceIndex2;
		int32_t field_80;
		int32_t field_84;
		int32_t field_88;
		int32_t field_8C;
		int32_t field_90;
		int32_t field_94;
		int32_t SoundTrackerDatumIndex;
		int32_t field_9C;
		int32_t Pitch_field_A0;
		float Volume;
		int32_t RandomSeed;
		int8_t PitchRangeBlockIndex;
		int8_t PitchRangePermutationBlockIndex;
		int16_t PitchRangePermutationChunkIndex;
		int8_t field_B0;
		int8_t field_B1;
		int16_t field_B2;
		int32_t PlaybackControllerDatumIndex;
		int16_t SoundGlobalIndex;
		int16_t field_BA;
		int32_t field_BC;
		int32_t field_C0;
		int32_t field_C4;
	};
	static_assert(sizeof(SoundSourceDatum) == 0xC8, "Invalid SoundSourceDatum size");

	struct LoopingSoundDatum : DatumBase {
		int16_t field_2;
		int32_t field_4;
		int32_t LoopingSoundTagIndex;
		int32_t field_C;
		int32_t field_10;

		// Block of size 0x4C, copied into SoundSource sometimes
		struct {
			int32_t field_14;
			int32_t field_18;
			int32_t field_1C;
			int32_t field_20;
			int32_t field_24;
			int32_t field_28;
			int32_t field_2C;
			int32_t field_30;
			int32_t field_34;
			int32_t field_38;
			int32_t field_3C;
			int32_t field_40;
			int32_t field_44;
			int32_t field_48;
			int32_t field_4C;
			int32_t field_50;
			int32_t field_54;
			int32_t field_58;
			int32_t field_5C;
		};
		

		int32_t field_60;
		DatumHandle PlaybackControllerHandle;
		int32_t field_68;
		int32_t field_6C;
		int32_t field_70;
		int32_t field_74;
		int32_t field_78;
		int32_t field_7C;
		int32_t field_80;
		int32_t field_84;
		int32_t field_88;
		int32_t field_8C;
		int32_t field_90;
		int32_t field_94;

		TrackDatum Track1;
		TrackDatum Track2;
		TrackDatum Track3;
		TrackDatum Track4;
	};
	static_assert(sizeof(LoopingSoundDatum) == 0x128, "Invalid LoopingSoundDatum size");

	

	struct SoundEffectDatum : DatumBase {
		int16_t field_2;
		int32_t field_4;
		int32_t field_8;
		int32_t field_C;
	};
	static_assert(sizeof(SoundEffectDatum) == 0x10, "Invalid SoundEffectDatum size");

	struct SoundTrackerDatum : DatumBase {
		int16_t field_2;
		int32_t field_4;
		int32_t field_8;
		int32_t field_C;
		int32_t field_10;
		int32_t field_14;
		int32_t field_18;
		int32_t field_1C;
		int32_t field_20;
		int32_t field_24;
		int32_t field_28;
		int32_t field_2C;
		int32_t field_30;
		int32_t field_34;
		int32_t field_38;
		int32_t field_3C;
		int32_t field_40;
		int32_t field_44;
		int32_t field_48;
		int32_t field_4C;
		int32_t field_50;
		int32_t field_54;
		int32_t field_58;
		int32_t field_5C;
		int32_t field_60;
		int32_t field_64;
		int32_t field_68;
		int32_t field_6C;
		int32_t field_70;
		int32_t field_74;
		int32_t field_78;
		int32_t field_7C;
		int32_t field_80;
		int32_t field_84;
		int32_t field_88;
		int32_t field_8C;
		int32_t field_90;
		int32_t field_94;
		int32_t field_98;
		int32_t field_9C;
		int32_t field_A0;
		int32_t field_A4;
		int32_t field_A8;
		int32_t field_AC;
		int32_t field_B0;
		int32_t field_B4;
		int32_t field_B8;
		int32_t field_BC;
		int32_t field_C0;
		int32_t field_C4;
		int32_t field_C8;
		int32_t field_CC;
		int32_t field_D0;
		int32_t field_D4;
		int32_t field_D8;
		int32_t field_DC;
		int32_t field_E0;
		int32_t field_E4;
		int32_t field_E8;
		int32_t field_EC;
		int32_t field_F0;
		int32_t field_F4;
		int32_t field_F8;
		int32_t field_FC;
		int32_t field_100;
		int32_t field_104;
		int32_t field_108;
		int32_t field_10C;
		int32_t field_110;
		int32_t field_114;
		int32_t field_118;
		int32_t field_11C;
		int32_t field_120;
		int32_t field_124;
		int32_t field_128;
		int32_t field_12C;
		int32_t field_130;
		int32_t field_134;
		int32_t field_138;
		int32_t field_13C;
		int32_t field_140;
		int32_t field_144;
		int32_t field_148;
		int32_t field_14C;
		int32_t field_150;
		int32_t field_154;
		int32_t field_158;
		int32_t field_15C;
		int32_t field_160;
		int32_t field_164;
		int32_t field_168;
		int32_t field_16C;
		int32_t field_170;
		int32_t field_174;
		int32_t field_178;
		int32_t field_17C;
	};
	static_assert(sizeof(SoundTrackerDatum) == 0x180, "Invalid SoundTrackerDatum size");

	struct SoundPlaybackControllerDatum : DatumBase {
		int16_t Flags;
		int32_t field_4;
		int32_t RandomSeedValue;
		int32_t field_C;
		int32_t field_10;
		int32_t field_14;
		int32_t field_18;
	};
	static_assert(sizeof(SoundPlaybackControllerDatum) == 0x1C, "Invalid SoundPlaybackControllerDatum size");

	// May have 2 different versions...
	struct SoundDataUnknown {
		DatumHandle SoundSourceHandle;
		int32_t field_4;
		int32_t field_8;
		int32_t field_C;
		int32_t field_10;
		int32_t field_14;
		int32_t field_18;
		int32_t field_1C;
		int32_t field_20;
		int32_t field_24;
		int32_t field_28;
		int32_t field_2C;
		int32_t field_30;
		int32_t field_34;
		// Known
		
		//0x14
		//int16_t SoundState; // Used in the Halo Sound System class
		//0x18
		//float Unknown;
		//0x11
		//int8_t Flags;
		//0x28
		//int32_t SoundTagIndex;
		//0x30
		//int32_t PitchRangePermutationPointer; //used in an if statement
		//0x34
		//int32_t Unknown1; //used in an if statement could also be PitchRangePermutationPointer
		//0x2E
		//int16_t ChunkIndex;
	};
	static_assert(sizeof(SoundDataUnknown) == 0x38, "Invalid SoundDataUnknown size");

	// Global sound array
	struct SoundGlobalData {
		int32_t field_0;
		int32_t field_4;
		int32_t field_8;
		int32_t field_C;
		int32_t field_10;
		int32_t field_14;
		int32_t field_18;
		int32_t field_1C;
		int32_t field_20;
		int32_t field_24;
		int32_t field_28;
		int32_t field_2C;
		int32_t field_30;
		int32_t field_34;
		int32_t field_38;
		int32_t field_3C;
		int32_t field_40;
		int32_t field_44;
		int32_t field_48;
		int32_t field_4C;
		int32_t field_50;
		int32_t field_54;
		int32_t field_58;
		int32_t field_5C;
		int32_t field_60;
		int32_t field_64;
		int32_t field_68;
		int32_t field_6C;
		int32_t field_70;
		int32_t field_74;
		int32_t field_78;
		int32_t field_7C;
		int32_t field_80;
		int32_t field_84;
		int32_t field_88;
		int32_t field_8C;
		int32_t field_90;
		int32_t field_94;
		int32_t field_98;
		int32_t field_9C;
		int32_t field_A0;
		int32_t field_A4;
		int32_t field_A8;
		int32_t field_AC;
		int32_t field_B0;
		int32_t field_B4;
		int32_t field_B8;
		int32_t field_BC;
		int32_t field_C0;
		int32_t field_C4;
		int32_t field_C8;
		int32_t field_CC;
		int32_t field_D0;
		int32_t field_D4;
		int32_t field_D8;
		int32_t field_DC;
		int32_t field_E0;
		int32_t field_E4;
		int32_t field_E8;
		int32_t field_EC;
		int32_t field_F0;
		int32_t field_F4;
		int32_t field_F8;
		int32_t field_FC;
		int32_t field_100;
		int32_t field_104;
		int32_t field_108;
		int32_t field_10C;
		int32_t field_110;
		int32_t field_114;
		int32_t field_118;
		int32_t field_11C;
		int32_t field_120;
		int32_t field_124;
		int32_t field_128;
		int32_t field_12C;
		int32_t field_130;
		int32_t field_134;
		int32_t field_138;
		int32_t field_13C;
		int32_t field_140;
		int32_t field_144;
		int32_t field_148;
		int32_t field_14C;
		int32_t field_150;
		int32_t field_154;
		int32_t field_158;
		int32_t field_15C;
		int32_t field_160;
		int32_t field_164;
		int32_t field_168;
		int32_t field_16C;
		int32_t field_170;
		int32_t field_174;
		int32_t field_178;
		int32_t field_17C;
		int32_t field_180;
		int32_t field_184;
		int32_t field_188;
		int32_t field_18C;
		int32_t field_190;
		int32_t field_194;
		int32_t field_198;
		int32_t field_19C;
		int32_t field_1A0;
		int32_t field_1A4;
		int32_t field_1A8;
		int32_t field_1AC;
		int32_t field_1B0;
		int32_t field_1B4;
		int32_t field_1B8;
		int32_t field_1BC;
		int32_t field_1C0;
		int32_t field_1C4;
		int32_t field_1C8;
		int32_t field_1CC;
		int32_t field_1D0;
		int32_t field_1D4;
		int32_t field_1D8;
		int32_t field_1DC;
		int32_t field_1E0;
		int32_t field_1E4;
		int32_t field_1E8;
		int32_t field_1EC;
		int32_t field_1F0;
		int32_t field_1F4;
		int32_t field_1F8;
		int32_t field_1FC;
		int32_t field_200;
		int32_t field_204;
		int32_t field_208;
		int32_t field_20C;
		int32_t field_210;
		int32_t field_214;
		int32_t field_218;
		int32_t field_21C;
		int32_t field_220;
		int32_t field_224;
		int32_t field_228;
		int32_t field_22C;
		int32_t field_230;
		int32_t field_234;
		int32_t field_238;
		int32_t field_23C;
		int32_t field_240;
		int32_t field_244;
		int32_t field_248;
		int32_t field_24C;
		int32_t field_250;
		int32_t field_254;
		int32_t field_258;
		int32_t field_25C;
		int32_t field_260;
		int32_t field_264;
		int32_t field_268;
		int32_t field_26C;
		int32_t field_270;
		int32_t field_274;
		int32_t field_278;
		int32_t field_27C;
		int32_t field_280;
		int32_t field_284;
		int32_t field_288;
		int32_t field_28C;
		int32_t field_290;
		int32_t field_294;
		int32_t field_298;
		int32_t field_29C;
		int32_t field_2A0;
		int32_t field_2A4;
		int32_t field_2A8;
		int32_t field_2AC;
		int32_t field_2B0;
		int32_t field_2B4;
	};
	static_assert(sizeof(SoundGlobalData) == 0x2B8, "Invalid SoundGlobalData size");
	
	// Used to pass information to functions.
	struct SoundTagDataStruct {
		int32_t SoundTagIndex;
		Sound* SoundDefinition;
		DatumHandle SoundSourcesHandle;
		PitchRange* PitchRange;
		Permutation* Permutation;
	};
	static_assert(sizeof(SoundTagDataStruct) == 0x14, "Invalid SoundTagDataStruct size");
}
