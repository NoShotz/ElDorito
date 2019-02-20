#pragma once
#include "../../ElDorito.hpp"
#include "../Preferences/Preferences.hpp"
#include "../BlamData.hpp"
#include "../BlamObjects.hpp"
#include "../BlamPlayers.hpp"
#include "../../../new/game/game_globals.hpp"

namespace Blam::Memory
{
	struct tls_data;
	struct simulation_gamestate_entities;
	struct main_gamestate_timing;
	struct main_render_timing;
	struct main_time_globals;
	struct random_math_globals;
	struct game_globals;
	struct players_globals;
	struct game_engine_globals;
	struct local_game_engine_globals;
	struct game_time;
	struct breakable_surface_globals;
	struct breakable_surface_set_broken_event;
	struct player_mapping;
	struct director_globals;
	struct director_scripting;
	struct hs_thread_deterministic_data;
	struct hs_runtime;
	struct hs_global_data;
	struct hs_distributed_global_data;
	struct hs_thread_tracking_data;
	struct hs_thread_non_deterministic_data;
	struct effect;
	struct effect_event;
	struct effect_location;
	struct effect_counts;
	struct effect_geometry_sample;
	struct effect_messaging_queue;
	struct effect_lightprobes;
	struct havok_gamestate;
	struct player_control_globals;
	struct player_control_globals_deterministic;
	struct object_looping_sounds;
	struct game_sound_globals;
	struct game_sound_scripted_impulses;
	struct structure_seam_globals;
	struct visibility_active_portals;
	struct campaign_metagame;
	struct observer_globals;
	struct observer_gamestate;
	struct rumble_globals;
	struct bink_gamestate;
	struct sound_classes;
	struct game_allegiance_globals;
	struct atmosphere_fog_globals;
	struct scenario_soft_surface_globals;
	struct game_sound_player_effects_globals;
	struct cinematic_new_globals;
	struct cinematic_globals;
	struct cinematic_light_globals;
	struct physics_constants;
	struct recorded_animations;
	struct game_save_globals;
	struct s_rasterizer_screen_effect;
	struct player_effect_globals;
	struct scenario_interpolator_globals;
	struct survival_mode_globals;
	struct player_training_globals;
	struct scenario_kill_trigger_volume_state;
	struct deterministic_game_sound_globals;
	struct s_decal_system_datum;
	struct decal_counts;
	struct decal;
	struct decal_messaging_queue;
	struct impact_globals;
	struct impacts;
	struct impact_arrays;
	struct object_list_header;
	struct list_object;
	struct scripted_camera_globals;
	struct s_particle_system_datum;
	struct contrail_system;
	struct contrail;
	struct contrail_location;
	struct contrail_profile;
	struct particle_location;
	struct light_volume_location;
	struct light_volume;
	struct light_volume_system;
	struct beam_system;
	struct beam;
	struct beam_location;
	struct hue_saturation_control;
	struct ragdolls;
	struct particle_emitter;
	struct rasterizer_game_states;
	struct scripted_exposure_globals;
	struct render_hud_globals;
	struct water_interaction_ripples;
	struct render_texture_globals;
	struct render_game_globals;
	struct depth_of_field_globals;
	struct cached_object_render_states;
	struct particle_emitter_gpu_row;
	struct particle_emitter_gpu_1;
	struct beam_gpu;
	struct beam_gpu_row;
	struct contrail_gpu_row;
	struct contrail_gpu;
	struct light_volume_gpu;
	struct light_volume_gpu_row;
	struct render_object_globals;
	struct shield_render_cache_message;
	struct chud_persistent_user_data;
	struct chud_persistent_global_data;
	struct user_widget;
	struct first_person_orientation_globals;
	struct first_person_weapon_globals;
	struct cortana_globals;
	struct campaign_objectives;
	struct object_globals;
	struct objects_memory_pool;
	struct object_name_list;
	struct object_messaging_queue;
	struct damage_globals;
	struct object_render_data;
	struct object_placement;
	struct device_groups;
	struct object_scripting;
	struct object_broadphase;
	struct object_early_movers;
	struct object_schedule_globals;
	struct object_activation_regions;
	struct lights;
	struct lights_globals;
	struct nondeterministic_render_light_data;
	struct widget;
	struct recycling_volumes;
	struct recycling_group;
	struct muffin;
	struct leaf_system;
	struct antenna;
	struct cloth;
	struct actor;
	struct actor_firing_position;
	struct ai_reference_frame;
	struct ai_globals;
	struct ai_player_state;
	struct vocalization_records;
	struct vocalization_timers;
	struct command_scripts;
	struct objectives;
	struct task_records;
	struct squad;
	struct squad_group;
	struct swarm;
	struct swarm_spawner;
	struct spawner_globals;
	struct dynamic_firing_points;
	struct propref;
	struct prop;
	struct tracking;
	struct joint_state;
	struct clump;
	struct squad_patrol;
	struct flocks;
	struct formations;
	struct vision_mode;

	inline tls_data *GetTlsData()
	{
		// TODO: Replace all instances of GetMainTls with GetTlsData 
		// once all the needed structs for tls_data are written out.
		return *(tls_data **)ElDorito::GetMainTls();
	}

	struct tls_data
	{
		char *unknown0[2];
		simulation_gamestate_entities *simulation_gamestate_entities;
		main_gamestate_timing *main_gamestate_timing;
		main_render_timing *main_render_timing;
		main_time_globals *main_time_globals;
		Blam::Preferences *preferences;
		char *unknown1C[6];
		random_math_globals *random_math_globals;
		char *filo_related;
		game_globals *game_globals;
		DataArray<Blam::Players::PlayerDatum> *players_header;
		players_globals *players_globals;
		game_engine_globals *game_engine_globals;
		local_game_engine_globals *local_game_engine_globals;
		game_time *game_time;
		breakable_surface_globals *breakable_surface_globals;
		breakable_surface_set_broken_event *breakable_surface_set_broken_event;
		player_mapping *player_mapping;
		director_globals *director_globals;
		director_scripting *director_scripting;
		hs_thread_deterministic_data *hs_thread_deterministic_data;
		hs_runtime *hs_runtime;
		hs_global_data *hs_global_data;
		hs_distributed_global_data *hs_distributed_global_data;
		hs_thread_tracking_data *hs_thread_tracking_data;
		hs_thread_non_deterministic_data *hs_thread_non_deterministic_data;
		char *unknown80[8];
		effect *effect;
		effect_event *effect_event;
		effect_location *effect_location;
		effect_counts *effect_counts;
		effect_geometry_sample *effect_geometry_sample;
		effect_messaging_queue *effect_messaging_queue;
		effect_lightprobes *effect_lightprobes;
		havok_gamestate *havok_gamestate;
		char *unknownC0;
		player_control_globals *player_control_globals;
		player_control_globals_deterministic *player_control_globals_deterministic;
		object_looping_sounds *object_looping_sounds;
		game_sound_globals *game_sound_globals;
		game_sound_scripted_impulses *game_sound_scripted_impulses;
		structure_seam_globals *structure_seam_globals;
		visibility_active_portals *visibility_active_portals;
		campaign_metagame *campaign_metagame;
		observer_gamestate *observer_gamestate;
		observer_globals *observer_globals;
		rumble_globals *rumble_globals;
		bink_gamestate *bink_gamestate;
		char *unknownF4;
		char *c_font_cache_mt_safe;
		sound_classes *sound_classes;
		game_allegiance_globals *game_allegiance_globals;
		atmosphere_fog_globals *atmosphere_fog_globals;
		scenario_soft_surface_globals *scenario_soft_surface_globals;
		game_sound_player_effects_globals *game_sound_player_effects_globals;
		char *havok_proxies;
		char *unknown114[131];
		cinematic_new_globals *cinematic_new_globals;
		cinematic_globals *cinematic_globals;
		cinematic_light_globals *cinematic_light_globals;
		physics_constants *physics_constants;
		recorded_animations *recorded_animations;
		game_save_globals *game_save_globals;
		DataArray<s_rasterizer_screen_effect> *rasterizer_screen_effects;
		player_effect_globals *player_effect_globals;
		scenario_interpolator_globals *scenario_interpolator_globals;
		survival_mode_globals *survival_mode_globals;
		player_training_globals *player_training_globals;
		scenario_kill_trigger_volume_state *scenario_kill_trigger_volume_state;
		deterministic_game_sound_globals *deterministic_game_sound_globals;
		DataArray<s_decal_system_datum> *decal_system;
		decal_counts *decal_counts;
		decal *decal;
		decal_messaging_queue *decal_messaging_queue;
		impact_globals *impact_globals;
		impacts *impacts;
		impact_arrays *impact_arrays;
		object_list_header *object_list_header;
		list_object *list_object;
		scripted_camera_globals *scripted_camera_globals;
		DataArrayBase *particles;
		DataArray<s_particle_system_datum> *particle_system;
		contrail_system *contrail_system;
		contrail *contrail;
		contrail_location *contrail_location;
		contrail_profile *contrail_profile;
		particle_location *particle_location;
		light_volume_system *light_volume_system;
		light_volume_location *light_volume_location;
		light_volume *light_volume;
		beam_system *beam_system;
		beam *beam;
		beam_location *beam_location;
		char *unknown3B0_render_postprocess_color_tweaking;
		ragdolls *ragdolls;
		particle_emitter *particle_emitter;
		rasterizer_game_states *rasterizer_game_states;
		hue_saturation_control *hue_saturation_control;
		char *unknown3C4;
		scripted_exposure_globals *scripted_exposure_globals;
		render_hud_globals *render_hud_globals;
		water_interaction_ripples *water_interaction_ripples;
		render_texture_globals *render_texture_globals;
		render_game_globals *render_game_globals;
		depth_of_field_globals *depth_of_field_globals;
		cached_object_render_states *cached_object_render_states;
		particle_emitter_gpu_row *particle_emitter_gpu_row;
		particle_emitter_gpu_1 *particle_emitter_gpu_1;
		char *particle_emitter_gpu_2;
		beam_gpu *beam_gpu;
		beam_gpu_row *beam_gpu_row;
		char *particle_emitter_gpu_3;
		contrail_gpu_row *contrail_gpu_row;
		contrail_gpu *contrail_gpu;
		char *particle_emitter_gpu_4;
		light_volume_gpu *light_volume_gpu;
		light_volume_gpu_row *light_volume_gpu_row;
		char *particle_emitter_gpu_5;
		char *rasterizer_implicit_geometry_data;
		render_object_globals *render_object_globals;
		shield_render_cache_message *shield_render_cache_message;
		chud_persistent_user_data *chud_persistent_user_data;
		chud_persistent_global_data *chud_persistent_global_data;
		user_widget *user_widget_0;
		user_widget *user_widget_1;
		user_widget *user_widget_2;
		user_widget *user_widget_3;
		first_person_orientation_globals *first_person_orientation_globals;
		first_person_weapon_globals *first_person_weapon_globals;
		cortana_globals *cortana_globals;
		campaign_objectives *campaign_objectives;
		DataArray<Blam::Objects::ObjectHeader> *object_header;
		object_globals *object_globals;
		objects_memory_pool *objects_memory_pool;
		object_name_list *object_name_list;
		object_messaging_queue *object_messaging_queue;
		char *collideable_object;
		damage_globals *damage_globals;
		char *unknown464;
		char *noncollideable_object;
		char *unknown46C[2];
		object_render_data *object_render_data;
		char *damage;
		object_placement *object_placement;
		device_groups *device_groups;
		object_scripting *object_scripting;
		object_broadphase *object_broadphase;
		object_early_movers *object_early_movers;
		object_schedule_globals *object_schedule_globals;
		object_activation_regions *object_activation_regions;
		lights *lights;
		lights_globals *lights_globals;
		char *light_data_reference;
		char *light_cluster_reference;
		char *light_first_data;
		nondeterministic_render_light_data *nondeterministic_render_light_data;
		widget *widget;
		recycling_volumes *recycling_volumes;
		recycling_group *recycling_group;
		muffin *muffin;
		leaf_system *leaf_system;
		antenna *antenna;
		cloth *cloth;
		char *unknown4CC[20];
		actor *actor;
		actor_firing_position *actor_firing_position;
		ai_reference_frame *ai_reference_frame;
		ai_globals *ai_globals;
		ai_player_state *ai_player_state;
		vocalization_records *vocalization_records;
		vocalization_timers *vocalization_timers;
		command_scripts *command_scripts;
		objectives *objectives;
		task_records *task_records;
		squad *squad;
		squad_group *squad_group;
		swarm *swarm;
		swarm_spawner *swarm_spawner;
		spawner_globals *spawner_globals;
		dynamic_firing_points *dynamic_firing_points;
		propref *propref;
		prop *prop;
		tracking *tracking;
		joint_state *joint_state;
		clump *clump;
		squad_patrol *squad_patrol;
		flocks *flocks;
		formations *formations;
		vision_mode *vision_mode;
		char *unknown580;
	};
	static_assert(sizeof(tls_data) == 4 * 353);

	// TODO: Move all these out of this file (it could get quite large check https://gist.github.com/theTwist84/33ca9c90bc49728ec7d043794ddfbd98/cb0d6b7389c444f464a1c6204a47b93c3e8cc815)
	// TODO: Actually RE all the below structs.
	struct simulation_gamestate_entities
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(simulation_gamestate_entities) == 0x10);

	struct main_gamestate_timing
	{
		long flags;
		float float4;
		float float8;
		float floatC;
		unsigned long dword10;
	};
	static_assert(sizeof(main_gamestate_timing) == 0x14);

	struct main_render_timing
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
		unsigned long dword10;
	};
	static_assert(sizeof(main_render_timing) == 0x14);

	struct main_time_globals
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
		unsigned long dword10;
		unsigned long dword14;
		unsigned long dword18;
		unsigned long dword1C;
		unsigned long dword20;
		unsigned long dword24;
		unsigned long dword28;
		unsigned long dword2C;
		unsigned long dword30;
		unsigned long dword34;
		unsigned long dword38;
		unsigned long dword3C;
	};
	static_assert(sizeof(main_time_globals) == 0x40);

	struct random_math_globals
	{
		unsigned long dword0;
		unsigned long dword4;
	};
	static_assert(sizeof(random_math_globals) == 0x8);

	struct game_globals
	{
		unsigned char unknown0;
		unsigned char unknown1;
		unsigned char unknown2;
		unsigned char unknown3;
		unsigned long bsp_load_state;
		unsigned long unknown8;
		unsigned long unknownC;
		Blam::GameOptions game_options;
		unsigned long unknown24B58; // mapname string_id?

		struct 
		{
			unsigned long unknown[32];
		} game_progression;

		unsigned char unknown24BDC[12];
		
		unsigned long end_match_wait_time;
		
		unsigned short primary_skulls_flags;
		unsigned char secondary_skulls_flags;

		unsigned char unknown24BEF[9];

		struct {
			struct {
				unsigned char unknown[32];
			} unknown[16];
		} unknown24BF8[3];

		unsigned char unknown251F8[16];
	};
	static_assert(sizeof(game_globals) == 0x25208);

	struct players_globals
	{
		char unknown[0x234];
	};
	static_assert(sizeof(players_globals) == 0x234);

	struct game_engine_globals
	{
		unsigned long Flags;
		unsigned long unknown4;
		unsigned long unknown8;
		unsigned short unknownC;
		unsigned short GameSimulation;
		unsigned long unknown16[7];
		unsigned long unknown2C;
		unsigned long unknown30[14390];
		unsigned short unknownE108;
		unsigned short unknownE10A;
		unsigned long unknownE10C;
		unsigned char unknownE110;
		unsigned char unknownE111[3];
		unsigned char unknownE114[124];
		unsigned char unknownE190[1832];
		unsigned char ForgeLegalNotice;
		unsigned char unknownE8B9[4311];
		unsigned short RoundTimeLimit;
		unsigned short unknownF992;
		unsigned long RoundTimeLimitTicksPerSecond;
		unsigned char unknownF996[1304];
		unsigned char MultiplayerScoreboard[0x420];
		unsigned char unknown102D0[0x3AD0];
		unsigned long unknown13DA0;
		unsigned long unknown13DA4[3];
		unsigned long GameType;
		unsigned long ObjectCount;
		unsigned long unknown13DB8;
		unsigned char unknown13DBC[6812];
	};
	static_assert(sizeof(game_engine_globals) == 0x15858);

	struct local_game_engine_globals
	{
		char unknown[0xC4];
	};
	static_assert(sizeof(local_game_engine_globals) == 0xC4);

	struct game_time
	{
		bool initialized;
		unsigned char : 8;
		unsigned short flags;
		unsigned short ticks_per_second;
		unsigned short : 16;
		float seconds_per_tick;
		unsigned long elapsed_ticks;
		unsigned long gamespeed;
		unsigned long unknown14;
		unsigned long unknown18;
		unsigned long unknown1C;
		unsigned long unknown20;
		unsigned long unknown24;
		unsigned long unknown28;
	};
	static_assert(sizeof(game_time) == 0x2C);

	struct breakable_surface_globals
	{
		char unknown[0x3CE18];
	};
	static_assert(sizeof(breakable_surface_globals) == 0x3CE18);

	struct breakable_surface_set_broken_event
	{
		char unknown[0x464];
	};
	static_assert(sizeof(breakable_surface_set_broken_event) == 0x464);

	struct player_mapping
	{
		unsigned short word0;
		unsigned short word2;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
		unsigned long dword10;
		unsigned long dword14;
		unsigned long dword18;
		unsigned long dword1C;
		unsigned long dword20;
		unsigned long dword24;
		unsigned long dword28;
		unsigned long dword2C;
		unsigned long dword30;
		unsigned char dword34[64];
		unsigned char dword74[64];
		unsigned short wordB4;
		unsigned long dwordB8;
		unsigned long dwordBC;
		unsigned long dwordC0;
		unsigned long dwordC4;
		unsigned long dwordC8;
		unsigned long dwordCC;
		unsigned long dwordD0;
		unsigned long dwordD4;
		unsigned long long qwordD8;
		unsigned long long qwordE0;
	};
	static_assert(sizeof(player_mapping) == 0xE8);

	struct director_globals
	{
		char unknown[0x5C0];
	};
	static_assert(sizeof(director_globals) == 0x5C0);

	struct director_scripting
	{
		char unknown0;
	};
	static_assert(sizeof(director_scripting) == 0x1);

	struct hs_thread_deterministic_data
	{
		char unknown[0x524];
	};
	static_assert(sizeof(hs_thread_deterministic_data) == 0x524);

	struct hs_runtime
	{
		unsigned long dword0;
		unsigned long dword4;
	};
	static_assert(sizeof(hs_runtime) == 0x8);

	struct hs_global_data
	{
		unsigned long dword0;
		unsigned long dword4;
	};
	static_assert(sizeof(hs_global_data) == 0x8);

	struct hs_distributed_global_data
	{
		char unknown[0x2C];
	};
	static_assert(sizeof(hs_distributed_global_data) == 0x2C);

	struct hs_thread_tracking_data
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(hs_thread_tracking_data) == 0xC);

	struct hs_thread_non_deterministic_data
	{
		char unknown[0x524];
	};
	static_assert(sizeof(hs_thread_non_deterministic_data) == 0x524);

	struct effect
	{
		char unknown[0xA0];
	};
	static_assert(sizeof(effect) == 0xA0);

	struct effect_event
	{
		char unknown[0x14];
	};
	static_assert(sizeof(effect_event) == 0x14);

	struct effect_location
	{
		char unknown[0x40];
	};
	static_assert(sizeof(effect_location) == 0x40);

	struct effect_counts
	{
		char unknown[0x18];
	};
	static_assert(sizeof(effect_counts) == 0x18);

	struct effect_geometry_sample
	{
		char unknown[0x28];
	};
	static_assert(sizeof(effect_geometry_sample) == 0x28);

	struct effect_messaging_queue
	{
		char unknown[0x17084];
	};
	static_assert(sizeof(effect_messaging_queue) == 0x17084);

	struct effect_lightprobes
	{
		char unknown[0xFE00];
	};
	static_assert(sizeof(effect_lightprobes) == 0xFE00);

	struct havok_gamestate
	{
		unsigned long dword0;
		unsigned long dword4;
	};
	static_assert(sizeof(havok_gamestate) == 0x8);

	struct player_control_globals
	{
		char unknown[0x8B0];
	};
	static_assert(sizeof(player_control_globals) == 0x8B0);

	struct player_control_globals_deterministic
	{
		char unknown[0x80];
	};
	static_assert(sizeof(player_control_globals_deterministic) == 0x80);

	struct object_looping_sounds
	{
		char unknown[0x20];
	};
	static_assert(sizeof(object_looping_sounds) == 0x20);

	struct game_sound_globals
	{
		char unknown[0x154];
	};
	static_assert(sizeof(game_sound_globals) == 0x154);

	struct game_sound_scripted_impulses
	{
		char unknown[0x200];
	};
	static_assert(sizeof(game_sound_scripted_impulses) == 0x200);

	struct structure_seam_globals
	{
		char unknown[0x14614];
	};
	static_assert(sizeof(structure_seam_globals) == 0x14614);

	struct visibility_active_portals
	{
		char unknown[0x800];
	};
	static_assert(sizeof(visibility_active_portals) == 0x800);

	struct campaign_metagame
	{
		char unknown[0x1A158];
	};
	static_assert(sizeof(campaign_metagame) == 0x1A158);

	struct observer_globals
	{
		struct player_data
		{
			char data[0x3C8];
		};
		static_assert(sizeof(player_data) == 0x3C8);

		player_data players[4];
		char unknownF20[8];
	};
	static_assert(sizeof(observer_globals) == 0xF28);

	struct observer_gamestate
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(observer_gamestate) == 0xC);

	struct rumble_globals
	{
		struct player_data
		{
			char data[0x88];
		};
		static_assert(sizeof(player_data) == 0x88);

		player_data players[4];
		float unknown220;
		float unknown224;
		float unknown228;
	};
	static_assert(sizeof(rumble_globals) == 0x22C);

	struct bink_gamestate
	{
		unsigned long dword0;
		unsigned long dword4;
	};
	static_assert(sizeof(bink_gamestate) == 0x8);

	struct sound_classes
	{
		char unknown[0x1144];
	};
	static_assert(sizeof(sound_classes) == 0x1144);

	struct game_allegiance_globals
	{
		char unknown[0x184];
	};
	static_assert(sizeof(game_allegiance_globals) == 0x184);

	struct atmosphere_fog_globals
	{
		char unknown[0x14];
	};
	static_assert(sizeof(atmosphere_fog_globals) == 0x14);

	struct scenario_soft_surface_globals
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(scenario_soft_surface_globals) == 0x10);

	struct game_sound_player_effects_globals
	{
		char unknown[0x28];
	};
	static_assert(sizeof(game_sound_player_effects_globals) == 0x28);

	struct cinematic_new_globals
	{
		char unknown[0x3C];
	};
	static_assert(sizeof(cinematic_new_globals) == 0x3C);

	struct cinematic_globals
	{
		long unknown0;
		char show_letterbox;
		char start_stop;
		char skip_start_stop;
		char suppress_bsp_object_creation;
		char unknow8[24];
		unsigned long subtitle_string_id;
		float subtitle_time_shown;
		float subtitle_time_shown2;
		char unknown2C[2];
		char outro_start_stop;
		char unknown2F[10201];
	};
	static_assert(sizeof(cinematic_globals) == 0x2808);

	struct cinematic_light_globals
	{
		char unknown[0xB2C8];
	};
	static_assert(sizeof(cinematic_light_globals) == 0xB2C8);

	struct physics_constants
	{
		unsigned long gravity;
		unsigned long water_density;
		unsigned long air_density;
		unsigned long dwordC;
		unsigned long dword10;
		float float14;
		unsigned long dword18;
		unsigned long dword1C;
	};
	static_assert(sizeof(physics_constants) == 0x20);

	struct recorded_animations
	{
		char unknown[0xA4];
	};
	static_assert(sizeof(recorded_animations) == 0xA4);

	struct game_save_globals
	{
		char unknown[0x18];
	};
	static_assert(sizeof(game_save_globals) == 0x18);

	struct s_rasterizer_screen_effect : Blam::DatumBase
	{
		uint16_t field_2;
		uint32_t tag_index;
		float seconds_active;
		Blam::Math::RealVector3D position;
		uint32_t object_index;
		uint32_t field_1c;
		Blam::Math::RealVector3D field_20;
		Blam::Math::RealVector3D field_2c;
		uint32_t field_38;
	};
	static_assert(sizeof(s_rasterizer_screen_effect) == 0x3C);

	struct player_effect_globals
	{
		struct player_data
		{
			char data[0xE4];
		};
		static_assert(sizeof(player_data) == 0xE4);

		char unknown0[0x10];
		player_data players[4];
	};
	static_assert(sizeof(player_effect_globals) == 0x3A0);

	struct scenario_interpolator_globals
	{
		char unknown[0x204];
	};
	static_assert(sizeof(scenario_interpolator_globals) == 0x204);

	struct survival_mode_globals
	{
		long lives;
		short set;
		short round;
		short wave;
		short unknownA;
		short set_multiplier;
		short unknown10;
		long round_multiplier;
		short waves_per_round;
		short rounds_per_set;
		long unknown18;
		long unknown1C;
		long unknown20;
		long unknown24;
		long unknown28;
		long unknown2C;
		long scoreboard;
		char unknown34[464];
	};
	static_assert(sizeof(survival_mode_globals) == 0x204);

	struct player_training_globals
	{
		struct training_data
		{
			enum activation_flags : unsigned char
			{
				flashlight = 1 << 0,
				crouch = 1 << 1,
				stealth = 1 << 2,
				jump = 1 << 4
			};

			unsigned long long unknown0;
			unsigned long long unknown8[18];
			unsigned long unknown98;
			unsigned long unknown9C;
			unsigned long long unknownA0[40];
			unsigned long long unknown1E0;
			unsigned long long unknown1E8;
			unsigned long long unknown1F0;
			unsigned long long unknown1F8;
			activation_flags flags;
			unsigned char unknown201[11];
			unsigned char unknown20C;
			unsigned char unknown20D[43];
		};
		static_assert(sizeof(training_data) == 0x238);

		training_data players[4];
		unsigned long unknown8E0;
		unsigned char unknown8E4;
		unsigned char unknown8E5;
		unsigned short unknown8E6;

	};
	static_assert(sizeof(player_training_globals) == 0x8E8);

	struct scenario_kill_trigger_volume_state
	{
		char unknown[0x84];
	};
	static_assert(sizeof(scenario_kill_trigger_volume_state) == 0x84);

	struct deterministic_game_sound_globals
	{
		char unknown[0x1300];
	};
	static_assert(sizeof(deterministic_game_sound_globals) == 0x1300);

	struct s_decal_system_datum : Blam::DatumBase
	{
		short : 16;
		long tag_index;
		long unknown8;
		long unknownC;
		long unknown10;
		long unknown14;
		long unknown18;
		long unknown1C;
		long unknown20;
		long unknown24;
		long unknown28;
		long unknown2C;
		long unknown30;
		long unknown34;
		long unknown38;
		long unknown3C;
		long unknown40;
		long unknown44;
		long unknown48;
		long unknown4C;
		char unknown50[0x307];
	};
	static_assert(sizeof(s_decal_system_datum) == 0x358);

	struct decal_counts
	{
		char unknown[0x20];
	};
	static_assert(sizeof(decal_counts) == 0x20);

	struct decal
	{
		char unknown[0x130];
	};
	static_assert(sizeof(decal) == 0x130);

	struct decal_messaging_queue
	{
		char unknown[0x824];
	};
	static_assert(sizeof(decal_messaging_queue) == 0x824);

	struct impact_globals
	{
		unsigned char unknown0[0x8C];
	};
	static_assert(sizeof(impact_globals) == 0x8C);

	struct impacts
	{
		unsigned char unknown0[0xB4];
	};
	static_assert(sizeof(impacts) == 0xB4);

	struct impact_arrays
	{
		unsigned char unknown0[0x88];
	};
	static_assert(sizeof(impact_arrays) == 0x88);

	struct object_list_header
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(object_list_header) == 0xC);

	struct list_object
	{
		char unknown[0x8C];
	};
	static_assert(sizeof(list_object) == 0x8C);

	struct scripted_camera_globals
	{
		unsigned char unknown0[0xF0];
	};
	static_assert(sizeof(scripted_camera_globals) == 0xF0);

	struct s_particle_system_datum : Blam::DatumBase
	{
		short particle_tag_index;
		long unknown4;
		long unknown8;
		long unknownC;
		long unknown10;
		long unknown14;
		long unknown18;
		long unknown1C;
		long unknown20;
		long unknown24;
		long unknown28;
		long unknown2C;
		long unknown30;
		long unknown34;
		long unknown38;
		long unknown3C;
		long unknown40;
		long unknown44;
		long unknown48;
		long unknown4C;
		long unknown50;
		long unknown54;
	};
	static_assert(sizeof(s_particle_system_datum) == 0x58);

	struct contrail_system
	{
		char unknown[0x4C];
	};
	static_assert(sizeof(contrail_system) == 0x4C);

	struct contrail
	{
		char unknown[0x4C];
	};
	static_assert(sizeof(contrail) == 0x4C);

	struct contrail_location
	{
		char unknown[0x60];
	};
	static_assert(sizeof(contrail_location) == 0x60);

	struct contrail_profile
	{
		char unknown[0x4C];
	};
	static_assert(sizeof(contrail_profile) == 0x4C);

	struct particle_location
	{
		char unknown[0x60];
	};
	static_assert(sizeof(particle_location) == 0x60);

	struct light_volume_location
	{
		char unknown[0x2C];
	};
	static_assert(sizeof(light_volume_location) == 0x2C);

	struct light_volume
	{
		char unknown[0x34];
	};
	static_assert(sizeof(light_volume) == 0x34);

	struct light_volume_system
	{
		char unknown[0x2C];
	};
	static_assert(sizeof(light_volume_system) == 0x2C);

	struct beam_system
	{
		char unknown[0x34];
	};
	static_assert(sizeof(beam_system) == 0x34);

	struct beam
	{
		char unknown[0x2C];
	};
	static_assert(sizeof(beam) == 0x2C);

	struct beam_location
	{
		char unknown[0x30];
	};
	static_assert(sizeof(beam_location) == 0x30);

	struct hue_saturation_control
	{
		unsigned long graphics_override;
		unsigned long saturation;
		unsigned long color;
		unsigned long dwordC;
		unsigned long dword10;
	};
	static_assert(sizeof(hue_saturation_control) == 0x14);

	struct ragdolls
	{
		char unknown[0x130];
	};
	static_assert(sizeof(ragdolls) == 0x130);

	struct particle_emitter
	{
		char unknown[0x90];
	};
	static_assert(sizeof(particle_emitter) == 0x90);

	struct rasterizer_game_states
	{
		char motion_blur;
		char atmosphere_fog;
		char patchy_fog;
		char weather;
		char cinematic_motion_blur;
		char unknown5[39];
		char autoexposure;
		char unknown44[475];
	};
	static_assert(sizeof(rasterizer_game_states) == 0x208);

	struct scripted_exposure_globals
	{
		char unknown[0x34];
	};
	static_assert(sizeof(scripted_exposure_globals) == 0x34);

	struct render_hud_globals
	{
		char unknown[0x480];
	};
	static_assert(sizeof(render_hud_globals) == 0x480);

	struct water_interaction_ripples
	{
		struct ripple_data
		{
			unsigned long unknown[40];
		};
		static_assert(sizeof(ripple_data) == 0xA0);
		ripple_data ripples[32];
	};
	static_assert(sizeof(water_interaction_ripples) == 0x1400);

	struct render_texture_globals
	{
		char camera_enable;
		char camera_dynamic_lights_enable;
		short unknown2;
		long camera_render_mode;
		long unknown8;
		long unknownC;
		long unknown10;
		long unknown14;
		long unknown18;
		long camera_object_handle;
		long camera_marker_name;
		long unknown24;
		long camera_position_world_x;
		long camera_position_world_y;
		long camera_position_world_z;
		long camera_target_object_x;
		long camera_target_object_y;
		long camera_target_object_z;
		char unknown40[28];
		float camera_fov;
		long aspect_ratio;
		long camera_resolution_width;
		long camera_resolution_height;
	};
	static_assert(sizeof(render_texture_globals) == 0x6C);

	struct render_game_globals
	{
		char unknown[0xD80];
	};
	static_assert(sizeof(render_game_globals) == 0xD80);

	struct depth_of_field_globals
	{
		bool enable;
		char unknown1[3];
		float dword4;
		float dword8;
		float dwordC;
		float intensity;
		float dword14;
		float dword18;
		float dword1C;
		float dword20;
		float dword24;
		float dword28;
		float dword2C;
		float dword30;
		float dword34;
		float dword38;
		float dword3C;
	};
	static_assert(sizeof(depth_of_field_globals) == 0x40);

	struct cached_object_render_states
	{
		char unknown[0x4D8];
	};
	static_assert(sizeof(cached_object_render_states) == 0x4D8);

	struct particle_emitter_gpu_row
	{
		char unknown[0x18];
	};
	static_assert(sizeof(particle_emitter_gpu_row) == 0x18);

	struct particle_emitter_gpu_1
	{
		char unknown[0x14];
	};
	static_assert(sizeof(particle_emitter_gpu_1) == 0x14);

	struct beam_gpu
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(beam_gpu) == 0x10);

	struct beam_gpu_row
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(beam_gpu_row) == 0xC);

	struct contrail_gpu_row
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(contrail_gpu_row) == 0x10);

	struct contrail_gpu
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
		unsigned long dword10;
	};
	static_assert(sizeof(contrail_gpu) == 0x14);

	struct light_volume_gpu
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(light_volume_gpu) == 0x10);

	struct light_volume_gpu_row
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(light_volume_gpu_row) == 0xC);

	struct render_object_globals
	{
		char unknown[0x3C040];
	};
	static_assert(sizeof(render_object_globals) == 0x3C040);

	struct shield_render_cache_message
	{
		char unknown[0x14];
	};
	static_assert(sizeof(shield_render_cache_message) == 0x14);

	struct chud_player_hud_elements
	{
		char unknown0[2];
		char crosshair;
		char shield;
		char grenades;
		char messages;
		char motion_sensor;
		char spike_grenades;
		char fire_grenades;
		char compass;
		char stamina;
		char energy_meters;
		char consumables;
	};

	struct chud_persistent_user_data
	{
		char unknown[0x14D];
		chud_player_hud_elements player_hud;
		char unknown181[0x316];
	};
	static_assert(sizeof(chud_persistent_user_data) == 0x470);

	struct chud_persistent_global_data
	{
		char unknown0[0x14D];
		chud_player_hud_elements player_hud[4];
		char unknown181[0x273];
		char bonus_round_show_timer;
		char bonus_round_start_timer;
		char unknown3F6[2];
		long bonus_round_set_timer;
		long bonus_round_set_target_score;
		char unknown3FC[0xF640];
	};
	static_assert(sizeof(chud_persistent_global_data) == 0xFA40);

	struct user_widget
	{
		char unknown[0x18];
	};
	static_assert(sizeof(user_widget) == 0x18);

	struct first_person_orientation_globals
	{
		struct player_data
		{
			unsigned char data[0x4B00];
		};
		static_assert(sizeof(player_data) == 0x4B00);

		player_data players[4];
	};
	static_assert(sizeof(first_person_orientation_globals) == 0x12C00);

	struct first_person_weapon_globals
	{
		struct player_data
		{
			struct unknown_data
			{
				unsigned char data[0x27A0];
			};

			long flags;
			unsigned char unknown4[0x68];
			unknown_data unknown_array[2];
			unsigned char unknown4FAC[0x54];
		};
		static_assert(sizeof(player_data) == 0x5000);

		player_data players[4];
	};
	static_assert(sizeof(first_person_weapon_globals) == 0x14000);

	struct cortana_globals
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(cortana_globals) == 0x10);

	struct campaign_objectives
	{
		char unknown[0x14];
	};
	static_assert(sizeof(campaign_objectives) == 0x14);

	struct object_globals
	{
		char unknown[0x6608];
	};
	static_assert(sizeof(object_globals) == 0x6608);

	struct objects_memory_pool
	{
		char unknown[0x44];
	};
	static_assert(sizeof(objects_memory_pool) == 0x44);

	struct object_name_list
	{
		char unknown[0x2000];
	};
	static_assert(sizeof(object_name_list) == 0x2000);

	struct object_messaging_queue
	{
		char unknown[0x4104];
	};
	static_assert(sizeof(object_messaging_queue) == 0x4104);

	struct damage_globals
	{
		char unknown[0x810];
	};
	static_assert(sizeof(damage_globals) == 0x810);

	struct object_render_data
	{
		char unknown[0x2000];
	};
	static_assert(sizeof(object_render_data) == 0x2000);

	struct object_placement
	{
		char unknown[0x320];
	};
	static_assert(sizeof(object_placement) == 0x320);

	struct device_groups
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
		unsigned long dwordC;
	};
	static_assert(sizeof(device_groups) == 0x10);

	struct object_scripting
	{
		char unknown[0x304];
	};
	static_assert(sizeof(object_scripting) == 0x304);

	struct object_broadphase
	{
		char unknown[0x32450];
	};
	static_assert(sizeof(object_broadphase) == 0x32450);

	struct object_early_movers
	{
		char unknown[0x2688];
	};
	static_assert(sizeof(object_early_movers) == 0x2688);

	struct object_schedule_globals
	{
		char unknown[0x27C];
	};
	static_assert(sizeof(object_schedule_globals) == 0x27C);

	struct object_activation_regions
	{
		char unknown[0x28];
	};
	static_assert(sizeof(object_activation_regions) == 0x28);

	struct lights
	{
		char unknown[0xE4];
	};
	static_assert(sizeof(lights) == 0xE4);

	struct lights_globals
	{
		char unknown[0x40];
	};
	static_assert(sizeof(lights_globals) == 0x40);

	struct nondeterministic_render_light_data
	{
		char unknown[0x2580];
	};
	static_assert(sizeof(nondeterministic_render_light_data) == 0x2580);

	struct widget
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(widget) == 0xC);

	struct recycling_volumes
	{
		char unknown[0x148];
	};
	static_assert(sizeof(recycling_volumes) == 0x148);

	struct recycling_group
	{
		char unknown[0x14];
	};
	static_assert(sizeof(recycling_group) == 0x14);

	struct muffin
	{
		char unknown[0x1890];
	};
	static_assert(sizeof(muffin) == 0x1890);

	struct leaf_system
	{
		char unknown[0x94C];
	};
	static_assert(sizeof(leaf_system) == 0x94C);

	struct antenna
	{
		char unknown[0x64];
	};
	static_assert(sizeof(antenna) == 0x64);

	struct cloth
	{
		char unknown[0x1704];
	};
	static_assert(sizeof(cloth) == 0x1704);

	struct actor
	{
		char unknown[0xA98];
	};
	static_assert(sizeof(actor) == 0xA98);

	struct actor_firing_position
	{
		char unknown[0x400];
	};
	static_assert(sizeof(actor_firing_position) == 0x400);

	struct ai_reference_frame
	{
		char unknown[0x4B0];
	};
	static_assert(sizeof(ai_reference_frame) == 0x4B0);

	struct ai_globals
	{
		char enable;
		char unknown1;
		short flags;
		char unknown4;
		char fast_and_dumb;
		char unknown5[1666];
	};
	static_assert(sizeof(ai_globals) == 0x688);

	struct ai_player_state
	{
		char unknown[0xB0];
	};
	static_assert(sizeof(ai_player_state) == 0xB0);

	struct vocalization_records
	{
		char unknown[0x5C];
	};
	static_assert(sizeof(vocalization_records) == 0x5C);

	struct vocalization_timers
	{
		char unknown[0xFB8];
	};
	static_assert(sizeof(vocalization_timers) == 0xFB8);

	struct command_scripts
	{
		char unknown[0x188];
	};
	static_assert(sizeof(command_scripts) == 0x188);

	struct objectives
	{
		unsigned long dword0;
		unsigned long dword4;
		unsigned long dword8;
	};
	static_assert(sizeof(objectives) == 0xC);

	struct task_records
	{
		char unknown[0x61A80];
	};
	static_assert(sizeof(task_records) == 0x61A80);

	struct squad
	{
		char unknown[0xEC];
	};
	static_assert(sizeof(squad) == 0xEC);

	struct squad_group
	{
		char unknown[0x24];
	};
	static_assert(sizeof(squad_group) == 0x24);

	struct swarm
	{
		char unknown[0x34];
	};
	static_assert(sizeof(swarm) == 0x34);

	struct swarm_spawner
	{
		char unknown[0x258];
	};
	static_assert(sizeof(swarm_spawner) == 0x258);

	struct spawner_globals
	{
		short unknown0;
	};
	static_assert(sizeof(spawner_globals) == 0x2);

	struct dynamic_firing_points
	{
		char unknown[0x584];
	};
	static_assert(sizeof(dynamic_firing_points) == 0x584);

	struct propref
	{
		char unknown[0x3C];
	};
	static_assert(sizeof(propref) == 0x3C);

	struct prop
	{
		char unknown[0xC4];
	};
	static_assert(sizeof(prop) == 0xC4);

	struct tracking
	{
		char unknown[0x100];
	};
	static_assert(sizeof(tracking) == 0x100);

	struct joint_state
	{
		char unknown[0xCC];
	};
	static_assert(sizeof(joint_state) == 0xCC);

	struct clump
	{
		char unknown[0x108];
	};
	static_assert(sizeof(clump) == 0x108);

	struct squad_patrol
	{
		char unknown[0x6C4];
	};
	static_assert(sizeof(squad_patrol) == 0x6C4);

	struct flocks
	{
		char unknown[0x4C];
	};
	static_assert(sizeof(flocks) == 0x4C);

	struct formations
	{
		char unknown[0x294];
	};
	static_assert(sizeof(formations) == 0x294);

	struct vision_mode
	{
		char unknown[0xF0];
	};
	static_assert(sizeof(vision_mode) == 0xF0);
}