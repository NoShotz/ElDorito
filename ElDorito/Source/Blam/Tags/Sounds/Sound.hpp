#pragma once

#include <Blam\Tags\Tags.hpp>
#include <Blam\Math\Bounds.hpp>
#include <Blam\Text\StringID.hpp>
#include <Blam\Tags\Sounds\SoundClasses.hpp>

namespace Blam::Tags::Sounds
{
	struct Sound : TagGroup<'snd!'>
	{
		enum class SoundClass : int8_t {
			ProjectileImpact,
			ProjectileDetonation,
			ProjectileFlyby,
			ProjectileDetonationLod,
			WeaponFire,
			WeaponReady,
			WeaponReload,
			WeaponEmpty,
			WeaponCharge,
			WeaponOverheat,
			WeaponIdle,
			WeaponMelee,
			WeaponAnimation,
			ObjectImpacts,
			ParticleImpacts,
			WeaponFireLod,
			WeaponFireLodFar,
			Unused2Impacts,
			UnitFootsteps,
			UnitDialog,
			UnitAnimation,
			UnitUnused,
			VehicleCollision,
			VehicleEngine,
			VehicleAnimation,
			VehicleEngineLod,
			DeviceDoor,
			DeviceUnused0,
			DeviceMachinery,
			DeviceStationary,
			DeviceUnused1,
			DeviceUnused2,
			Music,
			AmbientNature,
			AmbientMachinery,
			AmbientStationary,
			HugeAss,
			ObjectLooping,
			CinematicMusic,
			PlayerArmor,
			UnknownUnused1,
			AmbientFlock,
			NoPad,
			NoPadStationary,
			Arg,
			CortanaMission,
			CortanaGravemindChannel,
			MissionDialog,
			CinematicDialog,
			ScriptedCinematicFoley,
			Hud,
			GameEvent,
			Ui,
			Test,
			MultilingualTest,
			AmbientNatureDetails,
			AmbientMachineryDetails,
			InsideSurroundTail,
			OutsideSurroundTail,
			VehicleDetonation,
			AmbientDetonation,
			FirstPersonInside,
			FirstPersonOutside,
			FirstPersonAnywhere,
			UiPda
		};

		enum class SampleRate : int8_t {
			_22050Hz,
			_44100Hz,
			_32000Hz
		};

		enum class ImportType : int8_t {
			Unknown,
			SingleShot,
			SingleLayer,
			MultiLayer
		};

		struct PromotionRule;
		struct RuntimeTimer;
		struct PermutationChunk;
		struct Permutation;
		struct PitchRange;
		struct CustomPlayback;
		struct ExtraInfo;
		struct Language;

		uint32_t Flags;
		uint32_t Unknown1;
		uint32_t IsDialogue;

		SoundClass SoundClass;

		SampleRate SampleRate;

		uint8_t Unknown2;

		ImportType ImportType;

		// Playback parameters
		//FieldOverride, if distanceX is ticked, use the one in Soundclass instead
		uint32_t PlaybackParameterFlags;
		float DistanceA;
		float DistanceB;
		float DistanceC;
		float DistanceD;
		float SkipFraction;
		float MaximumBendPerSecond;
		float GainBase;
		float GainVariance;
		Math::Bounds<int16_t> RandomPitch;
		Math::Bounds<float> ConeAngle;
		float OuterConeGain;
		float OverrideFlags;
		float Azimuth;
		float PositionalGain;
		float FirstPersonGain;

		// Scale

		Math::Bounds<float> GainModifier;
		Math::Bounds<int16_t> PitchModifier;
		Math::Bounds<float> SkipFractionModifier;

		// Platform Codec

		int8_t Unknown3;
		int8_t LoadMode;
		int8_t Encoding;
		int8_t Compression;

		// Promotion

		TagBlock<PromotionRule> PromotionsRules;
		TagBlock<RuntimeTimer> RuntimeTimers;

		int32_t Unknown4;
		int32_t Unknown5;
		int32_t Unknown6;

		int32_t Unknown7;
		uint32_t TotalSampleSize;
		int32_t Unknown8;

		TagBlock<PitchRange> PitchRanges;
		TagBlock<CustomPlayback> CustomPlaybacks;
		TagBlock<ExtraInfo> ExtraInfos;
		TagBlock<Language> Languages;

		uint32_t Resource;
		uint32_t Padding;

		struct PromotionRule
		{
			int16_t PitchRangeIndex;
			int16_t MaximumPlayingCount;
			float SupressionTime;
			int32_t Unknown1;
			int32_t Unknown2;
		};
		TAG_STRUCT_SIZE_ASSERT(PromotionRule, 0x10);

		struct RuntimeTimer
		{
			int32_t Unknown;
		};
		TAG_STRUCT_SIZE_ASSERT(RuntimeTimer, 0x4);

		struct PermutationChunk
		{
			int32_t Offset;
			int32_t EncodedSize;
			int32_t RuntimeIndex;
			int32_t UnknownA;
			int32_t UnknownSize;
		};
		TAG_STRUCT_SIZE_ASSERT(PermutationChunk, 0x14);

		struct Permutation
		{
			Text::StringID Name;
			Math::Bounds<float> SkipFraction;
			uint32_t SampleSize;
			uint32_t PermutationNumber;
			uint32_t IsNotFirstPermutation;
			TagBlock<PermutationChunk> PermutationChunks;
			uint32_t Unknown1;
			uint32_t Unknown2;
		};
		TAG_STRUCT_SIZE_ASSERT(Permutation, 0x2C);

		struct PitchRange
		{
			Text::StringID Name;
			int16_t NaturalPitch;
			int16_t Unknown1;
			Math::Bounds<int16_t> Bend;
			Math::Bounds<int16_t> MaxGainPitch;
			Math::Bounds<int16_t> Unknown2;
			float Unknown3;
			uint32_t Unknown4;
			uint32_t Unknown5;
			uint32_t Unknown6;
			int16_t Unknown7;
			int16_t Unknown8;
			uint8_t PermutationCount;
			uint8_t Unknown9;
			int16_t Unknown10;
			TagBlock<Permutation> Permutations;
		};
		TAG_STRUCT_SIZE_ASSERT(PitchRange, 0x38);

		struct CustomPlayback
		{
			uint32_t FillMe;
		};
		TAG_STRUCT_SIZE_ASSERT(CustomPlayback, 0x4);

		struct ExtraInfo
		{
			uint32_t FillMe;
		};
		TAG_STRUCT_SIZE_ASSERT(ExtraInfo, 0x4);

		struct Language
		{
			uint32_t FillMe;
		};
		TAG_STRUCT_SIZE_ASSERT(Language, 0x4);
	};
	TAG_STRUCT_SIZE_ASSERT(Sound, 0xD4);
}
