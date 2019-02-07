#include "Functions.hpp"

namespace Blam::Sounds
{

	using namespace Blam::Tags::Sounds;

	void* tag_get(uint32_t tagGroup, int16_t tagIndex)
	{
		const auto sub_503370 = (int32_t(*)(uint32_t tag_group, int16_t tag_index))(0x503370);
		int32_t address = sub_503370(tagGroup, tagIndex);
		return reinterpret_cast<void*>(address);
	};

	ClassProperty* sound_class_get(int16_t type)
	{
		const auto sub_660CC0 = (ClassProperty*(*)(int16_t type))(0x660CC0);
		ClassProperty* soundClass = sub_660CC0(type);
		return soundClass;
	}

	double sound_sub_661D70(int16_t soundTagIndex, int32_t pitchRangeIndex)
	{
		Sound* sound = (Sound*)tag_get('snd!', soundTagIndex);
		PitchRange pitchRange = sound->PitchRanges[pitchRangeIndex];
		float unknown = (float)pitchRange.Unknown3;
		if (pitchRangeIndex == -1 || pitchRange.Name == -20 || unknown == 0.0)
		{
			if ((((int8_t)sound->PlaybackParameters.OverrideFlags) >> 1) & 1)
			{
				ClassProperty* soundClass = sound_class_get((int16_t)sound->SoundClass);
				return soundClass->Unknown15;
			}
			unknown = sound->PlaybackParameters.DistanceB;
		}
		return unknown;


	};

	int16_t sound_get_pitch_range_by_pitch(Sound* sound, float pitchModifier, int16_t fallbackIndex)
	{
		bool hasFlag14 = ((sound->Flags) & 0x4000) == 0;
		auto pitchRangeCount = sound->PitchRanges.Count;
		auto curPitchRangeIndex = -1;
		auto failure = -1;

		if (!hasFlag14)
		{
			curPitchRangeIndex = 0;

			if (pitchRangeCount > 0)
			{
				auto curPitchRange = sound->PitchRanges[0];
				while (curPitchRange.Name != 1236) // "lfe"
				{
					curPitchRangeIndex++;
					curPitchRange = sound->PitchRanges[curPitchRangeIndex];
					if (curPitchRangeIndex >= pitchRangeCount)
					{
						goto lfe_NOT_FOUND;
					}
				}
			}

		lfe_NOT_FOUND:

			//Will return if the fallback Index satisfies the right conditions
			if (fallbackIndex != -1 && fallbackIndex < pitchRangeCount)
			{
				auto curPitchRange = sound->PitchRanges[fallbackIndex];
				if ((curPitchRangeIndex == fallbackIndex || pitchModifier >= curPitchRange.MaxGainPitch.Lower && pitchModifier <= curPitchRange.MaxGainPitch.Upper) && curPitchRange.Unknown7>0)
				{
					return fallbackIndex;
				}
				return failure;
			}

			float max = FLT_MAX;
			auto result = 0;

			if (pitchRangeCount < 0)
				return failure;

			auto curIndex = 0;
			auto curPitchRange = sound->PitchRanges[curIndex];
			auto bendsMax = curPitchRange.Bend.Upper;
			auto bendsMin = 0;

			while (curPitchRangeIndex == curIndex || curPitchRange.PermutationCount <= 0)
			{
			INCR_INDEX:
				curIndex++;
				curPitchRange = sound->PitchRanges[curIndex];
				if (curIndex >= pitchRangeCount)
					return failure;
			}

			if (pitchModifier < curPitchRange.MaxGainPitch.Lower || curPitchRange.MaxGainPitch.Upper < pitchModifier)
			{
				bendsMax = curPitchRange.Bend.Upper;
				if (pitchModifier <= bendsMax)
					bendsMin = (int)((float)curPitchRange.Bend.Lower - pitchModifier);
				else
					bendsMin = (int)(pitchModifier - (float)bendsMax);

				if (max > (float)bendsMin)
				{
					failure = curIndex;
					max = (float)bendsMin;
				}
				goto INCR_INDEX;
			}

			//Verify that curIndex != -1 

			return curIndex;
		}

		return -1;
	}

	bool sound_is_valid_pitch_range_permutation(int32_t soundTagIndex, int8_t* data)
	{
		char pitchRangeIndex = *data;
		char permutationIndex = *(data + 1);

		if (soundTagIndex == -1 || pitchRangeIndex < 0 || permutationIndex < 0)
			return false;

		auto sound = (Blam::Tags::Sounds::Sound*)tag_get('snd!', soundTagIndex);

		if (pitchRangeIndex >= GetPitchRangeCount(sound))
			return false;

		auto pitchRange = GetPitchRange(sound, pitchRangeIndex);
		auto permutationCount = GetPermutationCount(pitchRange);

		if (permutationIndex < permutationCount)
			return true;

		return false;
	};

	//0x662A40 not sure of the name
	double sound_compute_pitch_modifier_min(Sound* sound, PitchRange* pitchRange, uint32_t SampleSize)
	{
		auto pitchRandomMin = sound->PlaybackParameters.RandomPitch.Upper;

		if (sound->PlaybackParameters.RandomPitch.Lower <= pitchRandomMin)
			pitchRandomMin = sound->PlaybackParameters.RandomPitch.Lower;

		auto PitchModifierMin = sound->Scale.PitchModifier.Upper;

		if (sound->Scale.PitchModifier.Lower <= PitchModifierMin)
			PitchModifierMin = sound->Scale.PitchModifier.Lower;

		double naturalPitchFactor = exp((pitchRange->NaturalPitch / 1200.0)*0.69314718);
		double SampleSizeFactor = exp((double)SampleSize);

		double result = (SampleSizeFactor*1000.0*naturalPitchFactor) / (((pitchRandomMin + pitchRandomMin) / 1200.0)*0.69314718 * globalSampleRates[(int)sound->SampleRate]);
		return result;
	}

	//0x662120
	double unknown(int32_t soundTagIndex, int32_t pitchRangeIndex, int32_t permutationIndex, float parameter)
	{
		auto sound = (Sound*)tag_get('snd!', soundTagIndex);
		auto pitchRange = GetPitchRange(sound, pitchRangeIndex);
		auto permutation = GetPermutation(pitchRange, permutationIndex);

		auto permutationPitchModifierMin = sound_compute_pitch_modifier_min(sound, pitchRange, permutation->SampleSize);
		auto naturalPitchModifier = exp((double)parameter - (double)pitchRange->NaturalPitch / 1200.0 * 0.69314718);

		return naturalPitchModifier * permutationPitchModifierMin;
	}

	//Find better names
	double sound_get_distance_d(int16_t soundTagIndex)
	{
		Sound* sound = (Sound*)tag_get('snd!', soundTagIndex);
		if (((int8_t)(sound->PlaybackParameters.PlaybackParameterFlags) >> 3 & 1))
		{
			ClassProperty* soundClass = sound_class_get((int16_t)sound->SoundClass);
			return soundClass->DistanceBoundsMax;
		}
		else
			return sound->PlaybackParameters.DistanceD;
	}

	double sound_get_distance_c(int16_t soundTagIndex)
	{
		Sound* sound = (Sound*)tag_get('snd!', soundTagIndex);
		if (((int8_t)(sound->PlaybackParameters.PlaybackParameterFlags) >> 2 & 1))
		{
			ClassProperty* soundClass = sound_class_get((int16_t)sound->SoundClass);
			return soundClass->DistanceBoundsMin;
		}
		else
			return sound->PlaybackParameters.DistanceC;
	}

	void PredictFirstPermutation(int16_t soundTagIndex) {
		if (soundTagIndex != -1) {
			Sound *sound = (Sound*)tag_get('snd!', soundTagIndex);
			if (GetPitchRangeCount(sound)) {
				PitchRange *pitchRange = GetPitchRange(sound, 0);
				if (GetPermutationCount(pitchRange)) {
					Permutation *permutation = GetPermutation(pitchRange, 0);
					PermutationChunk *chunk = GetPermutationChunk(permutation, 0);
					AllocateSound(soundTagIndex, chunk, 1);
				}
			}
		}
	}

	float GetGainUpperBound(Sound* sound) {
		return GetClassProperty(sound->SoundClass)->GainBoundsMax + sound->Scale.GainModifier.Upper;
	}

	float GetGainLowerBound(Sound* sound) {
		return  GetClassProperty(sound->SoundClass)->GainBoundsMin + sound->Scale.GainModifier.Lower;
	}

	ClassProperty* GetClassProperty(SoundClass type) {
		// Hacky af, lazy me
		int* g_global_def = (int*)0x022AAEB8;
		auto v1 = 0;

		if (*(g_global_def + 0xBC))
			v1 = *(g_global_def + 0xC0);

		auto classes = Blam::Tags::TagInstance(*((int *)v1 + 3)).GetDefinition<Classes>();
		return GetClassProperty(classes, type);
	}


	FMOD_RESULT SoundCreateFMODSound(Blam::SoundTagDataStruct* data, void* sound, char* a3) {

		static auto resource_get = (void*(__cdecl*)(void* resource))(0x563E10);

		auto chunk = GetPermutationChunk(data->Permutation, 0);
		auto soundDefinition = data->SoundDefinition;

		auto bufferSize = -1;																	// FMOD exInfo buffer size

		if (!chunk || chunk->Offset == -1 || !soundDefinition)									// If permutation chunk data offset is -1, invalid sound return error code 23.
			return FMOD_ERR_FILE_NOTFOUND;

		bool isStreaming = GetLoadMode(soundDefinition) == 1;
		auto compression = GetCompression(soundDefinition);

		int resource = (int)resource_get(&data->SoundDefinition->Resource);	
		char* soundData = (char *)(chunk->Offset + *(int *)(resource + 12));

		auto dataSize = 0x3FFFFFF & chunk->EncodedSize;											// Get real data size

		if (!soundData)																			// If pointer is not valid, return error code 23.
			return FMOD_ERR_FILE_NOTFOUND;

		// If sound definition is valid and Flag 11 is active, create a copy of the sound data.
		if ((soundDefinition->Flags >> 11) & 1) {
			char* newSoundData = new char[dataSize];
			memmove(newSoundData, soundData, dataSize);
			soundData = newSoundData;
		}

		FMOD::FMOD_CREATESOUNDEXINFO exInfo = FMOD::FMOD_CREATESOUNDEXINFO();					// Create the FMOD ExInfo struct
		exInfo.cbsize = 0x70;
		
		auto soundSource = (*soundSources)->Get(data->SoundSourcesHandle);

		FMOD::FMOD_MODE mode = (FMOD::FMOD_MODE)0x1A004048;

		if( (soundSource->field_2 & 0x00FF) == 2 && (soundSource->field_8) & 0x0001)			// If looping, set different FMOD_MODE
			mode = (FMOD::FMOD_MODE)0x1A00404A;

		// If is uncompressed (WAV)
		if (compression == 3) {
			mode = mode | FMOD::FMOD_OPENRAW;
			exInfo.format = FMOD::FMOD_SOUND_FORMAT_PCM16;
			
			exInfo.defaultfrequency = globalSampleRates[(int)GetSampleRate(soundDefinition)];	// Set frequency (sample rate)
			exInfo.numchannels = globalEncodings[GetEncoding(soundDefinition)];					// Set encoding (number of channels)
			soundData += 16;																	// Move pointer by 16 bytes
			bufferSize = dataSize - 32;															// Load the whole file except 32 bytes (not sure why yet)
		}
		// MPEG (MP3)
		else {

			if (!isStreaming)
				mode = mode | FMOD::FMOD_CREATECOMPRESSEDSAMPLE;

			if (compression == 8)
				exInfo.suggestedsoundtype = FMOD_SOUND_TYPE_MPEG;

			else
				exInfo.suggestedsoundtype = FMOD_SOUND_TYPE_FSB;

			bufferSize = dataSize;																// Load the whole file in memory
		}

		exInfo.length = bufferSize;

		FMOD_RESULT result = FMOD::FMOD_ERR_BADCOMMAND;											// Temp FMOD result value

		void* system = FMOD::GetSystemPointer();
		
		// Call FMOD create sound or stream
		if (!isStreaming) {
			result = FMOD::System::CreateSound(system, system, soundData, mode, &exInfo, sound);
		}
		else {
			result = FMOD::System::CreateStream(system, system, soundData, mode, &exInfo, sound);
		}
		return result;
	}

	int8_t UpdateSound(int32_t soundDatum0x38Index, float volume, int a3) {

		auto *soundDatum0x38 = &soundUnknown[soundDatum0x38Index];
		auto soundSource = (*soundSources)->Get(soundDatum0x38->SoundSourceHandle);

		auto soundDefinition = Blam::Tags::TagInstance(soundSource->SoundTagIndex).GetDefinition<Sound>();
		
		// memory crap, can you make this even more obscure ffs?
		//a4 = 0;                                      
		//memset(&v32, 0, 0x60u);
		//v36 = 0;
		//memset(&v37, 0, 0x450u);
		//

		if (soundSource->Flags2 & 0x100) {
			//v7 =1
		}
		//v39=v7
		float pitch20 = soundSource->Pitch_field_20;
		float pitchA0 = (float)soundSource->Pitch_field_A0;
		auto scaleBlock = GetScale(soundDefinition);

		float pitchModifier = ((scaleBlock->PitchModifier.Upper - scaleBlock->PitchModifier.Lower) * pitch20 + scaleBlock->PitchModifier.Lower) + pitchA0;
		
		//float gainUpperBound = GetGainUpperBound(sound);
		//float gainLowerBound = GetGainLowerBound(sound);
		//float gainScale = Math::random_seed_range(1, gainLowerBound, gainUpperBound, pitch20);
		// some weird fucketery to get a gain value from data
		//v45 = global_sound_unknown_gain_sub_5182D0((sound_class_type)sound3->sound_class);
		//f1 = *(float *)&pitch_range + (float)(v45 + f1);
		float gainModifier = 0;
		// Some memory related crap
		//sound_sub_5133E0(sound_datum_0x38_index, sound_datum_0xC8, a3, (int)&a4);

		auto pitchRangeBlock = GetPitchRange(soundDefinition, soundSource->PitchRangeBlockIndex);
		auto permutation = GetPermutation(pitchRangeBlock, soundSource->PitchRangePermutationBlockIndex);
		auto chunk = GetPermutationChunk(permutation, soundSource->PitchRangePermutationChunkIndex);

		return 0;
	}
}
