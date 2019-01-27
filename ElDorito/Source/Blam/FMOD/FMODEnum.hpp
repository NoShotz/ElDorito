#pragma once
namespace FMOD {

#define FMOD_CHANNEL_FREE -1;

	enum FMOD_RESULT
	{
		FMOD_OK,                        /* No errors. */
		FMOD_ERR_ALREADYLOCKED,         /* Tried to call lock a second time before unlock was called. */
		FMOD_ERR_BADCOMMAND,            /* Tried to call a function on a data type that does not allow this type of functionality (ie calling Sound::lock on a streaming sound). */
		FMOD_ERR_CDDA_DRIVERS,          /* Neither NTSCSI nor ASPI could be initialised. */
		FMOD_ERR_CDDA_INIT,             /* An error occurred while initialising the CDDA subsystem. */
		FMOD_ERR_CDDA_INVALID_DEVICE,   /* Couldn't find the specified device. */
		FMOD_ERR_CDDA_NOAUDIO,          /* No audio tracks on the specified disc. */
		FMOD_ERR_CDDA_NODEVICES,        /* No CD/DVD devices were found. */
		FMOD_ERR_CDDA_NODISC,           /* No disc present in the specified drive. */
		FMOD_ERR_CDDA_READ,             /* A CDDA read error occurred. */
		FMOD_ERR_CHANNEL_ALLOC,         /* Error trying to allocate a channel. */
		FMOD_ERR_CHANNEL_STOLEN,        /* The specified channel has been reused to play another sound. */
		FMOD_ERR_COM,                   /* A Win32 COM related error occured. COM failed to initialize or a QueryInterface failed meaning a Windows codec or driver was not installed properly. */
		FMOD_ERR_DMA,                   /* DMA Failure.  See debug output for more information. */
		FMOD_ERR_DSP_CONNECTION,        /* DSP connection error.  Connection possibly caused a cyclic dependancy.  Or tried to connect a tree too many units deep (more than 128). */
		FMOD_ERR_DSP_FORMAT,            /* DSP Format error.  A DSP unit may have attempted to connect to this network with the wrong format. */
		FMOD_ERR_DSP_NOTFOUND,          /* DSP connection error.  Couldn't find the DSP unit specified. */
		FMOD_ERR_DSP_RUNNING,           /* DSP error.  Cannot perform this operation while the network is in the middle of running.  This will most likely happen if a connection or disconnection is attempted in a DSP callback. */
		FMOD_ERR_DSP_TOOMANYCONNECTIONS,/* DSP connection error.  The unit being connected to or disconnected should only have 1 input or output. */
		FMOD_ERR_FILE_BAD,              /* Error loading file. */
		FMOD_ERR_FILE_COULDNOTSEEK,     /* Couldn't perform seek operation.  This is a limitation of the medium (ie netstreams) or the file format. */
		FMOD_ERR_FILE_DISKEJECTED,      /* Media was ejected while reading. */
		FMOD_ERR_FILE_EOF,              /* End of file unexpectedly reached while trying to read essential data (truncated data?). */
		FMOD_ERR_FILE_NOTFOUND,         /* File not found. */
		FMOD_ERR_FILE_UNWANTED,         /* Unwanted file access occured. */
		FMOD_ERR_FORMAT,                /* Unsupported file or audio format. */
		FMOD_ERR_HTTP,                  /* A HTTP error occurred. This is a catch-all for HTTP errors not listed elsewhere. */
		FMOD_ERR_HTTP_ACCESS,           /* The specified resource requires authentication or is forbidden. */
		FMOD_ERR_HTTP_PROXY_AUTH,       /* Proxy authentication is required to access the specified resource. */
		FMOD_ERR_HTTP_SERVER_ERROR,     /* A HTTP server error occurred. */
		FMOD_ERR_HTTP_TIMEOUT,          /* The HTTP request timed out. */
		FMOD_ERR_INITIALIZATION,        /* FMOD was not initialized correctly to support this function. */
		FMOD_ERR_INITIALIZED,           /* Cannot call this command after System::init. */
		FMOD_ERR_INTERNAL,              /* An error occured that wasn't supposed to.  Contact support. */
		FMOD_ERR_INVALID_ADDRESS,       /* On Xbox 360, this memory address passed to FMOD must be physical, (ie allocated with XPhysicalAlloc.) */
		FMOD_ERR_INVALID_FLOAT,         /* Value passed in was a NaN, Inf or denormalized float. */
		FMOD_ERR_INVALID_HANDLE,        /* An invalid object handle was used. */
		FMOD_ERR_INVALID_PARAM,         /* An invalid parameter was passed to this function. */
		FMOD_ERR_INVALID_POSITION,      /* An invalid seek position was passed to this function. */
		FMOD_ERR_INVALID_SPEAKER,       /* An invalid speaker was passed to this function based on the current speaker mode. */
		FMOD_ERR_INVALID_SYNCPOINT,     /* The syncpoint did not come from this sound handle. */
		FMOD_ERR_INVALID_VECTOR,        /* The vectors passed in are not unit length, or perpendicular. */
		FMOD_ERR_IRX,                   /* PS2 only.  fmodex.irx failed to initialize.  This is most likely because you forgot to load it. */
		FMOD_ERR_MAXAUDIBLE,            /* Reached maximum audible playback count for this sound's soundgroup. */
		FMOD_ERR_MEMORY,                /* Not enough memory or resources. */
		FMOD_ERR_MEMORY_CANTPOINT,      /* Can't use FMOD_OPENMEMORY_POINT on non PCM source data, or non mp3/xma/adpcm data if FMOD_CREATECOMPRESSEDSAMPLE was used. */
		FMOD_ERR_MEMORY_IOP,            /* PS2 only.  Not enough memory or resources on PlayStation 2 IOP ram. */
		FMOD_ERR_MEMORY_SRAM,           /* Not enough memory or resources on console sound ram. */
		FMOD_ERR_NEEDS2D,               /* Tried to call a command on a 3d sound when the command was meant for 2d sound. */
		FMOD_ERR_NEEDS3D,               /* Tried to call a command on a 2d sound when the command was meant for 3d sound. */
		FMOD_ERR_NEEDSHARDWARE,         /* Tried to use a feature that requires hardware support.  (ie trying to play a VAG compressed sound in software on PS2). */
		FMOD_ERR_NEEDSSOFTWARE,         /* Tried to use a feature that requires the software engine.  Software engine has either been turned off, or command was executed on a hardware channel which does not support this feature. */
		FMOD_ERR_NET_CONNECT,           /* Couldn't connect to the specified host. */
		FMOD_ERR_NET_SOCKET_ERROR,      /* A socket error occurred.  This is a catch-all for socket-related errors not listed elsewhere. */
		FMOD_ERR_NET_URL,               /* The specified URL couldn't be resolved. */
		FMOD_ERR_NET_WOULD_BLOCK,       /* Operation on a non-blocking socket could not complete immediately. */
		FMOD_ERR_NOTREADY,              /* Operation could not be performed because specified sound/DSP connection is not ready. */
		FMOD_ERR_OUTPUT_ALLOCATED,      /* Error initializing output device, but more specifically, the output device is already in use and cannot be reused. */
		FMOD_ERR_OUTPUT_CREATEBUFFER,   /* Error creating hardware sound buffer. */
		FMOD_ERR_OUTPUT_DRIVERCALL,     /* A call to a standard soundcard driver failed, which could possibly mean a bug in the driver or resources were missing or exhausted. */
		FMOD_ERR_OUTPUT_ENUMERATION,    /* Error enumerating the available driver list. List may be inconsistent due to a recent device addition or removal. */
		FMOD_ERR_OUTPUT_FORMAT,         /* Soundcard does not support the minimum features needed for this soundsystem (16bit stereo output). */
		FMOD_ERR_OUTPUT_INIT,           /* Error initializing output device. */
		FMOD_ERR_OUTPUT_NOHARDWARE,     /* FMOD_HARDWARE was specified but the sound card does not have the resources necessary to play it. */
		FMOD_ERR_OUTPUT_NOSOFTWARE,     /* Attempted to create a software sound but no software channels were specified in System::init. */
		FMOD_ERR_PAN,                   /* Panning only works with mono or stereo sound sources. */
		FMOD_ERR_PLUGIN,                /* An unspecified error has been returned from a 3rd party plugin. */
		FMOD_ERR_PLUGIN_INSTANCES,      /* The number of allowed instances of a plugin has been exceeded. */
		FMOD_ERR_PLUGIN_MISSING,        /* A requested output, dsp unit type or codec was not available. */
		FMOD_ERR_PLUGIN_RESOURCE,       /* A resource that the plugin requires cannot be found. (ie the DLS file for MIDI playback) */
		FMOD_ERR_RECORD,                /* An error occured trying to initialize the recording device. */
		FMOD_ERR_REVERB_INSTANCE,       /* Specified Instance in FMOD_REVERB_PROPERTIES couldn't be set. Most likely because it is an invalid instance number, or another application has locked the EAX4 FX slot. */
		FMOD_ERR_SUBSOUND_ALLOCATED,    /* This subsound is already being used by another sound, you cannot have more than one parent to a sound.  Null out the other parent's entry first. */
		FMOD_ERR_SUBSOUND_CANTMOVE,     /* Shared subsounds cannot be replaced or moved from their parent stream, such as when the parent stream is an FSB file. */
		FMOD_ERR_SUBSOUND_MODE,         /* The subsound's mode bits do not match with the parent sound's mode bits.  See documentation for function that it was called with. */
		FMOD_ERR_SUBSOUNDS,             /* The error occured because the sound referenced contains subsounds.  The operation cannot be performed on a parent sound, or a parent sound was played without setting up a sentence first. */
		FMOD_ERR_TAGNOTFOUND,           /* The specified tag could not be found or there are no tags. */
		FMOD_ERR_TOOMANYCHANNELS,       /* The sound created exceeds the allowable input channel count.  This can be increased using the maxinputchannels parameter in System::setSoftwareFormat. */
		FMOD_ERR_UNIMPLEMENTED,         /* Something in FMOD hasn't been implemented when it should be! contact support! */
		FMOD_ERR_UNINITIALIZED,         /* This command failed because System::init or System::setDriver was not called. */
		FMOD_ERR_UNSUPPORTED,           /* A command issued was not supported by this object.  Possibly a plugin without certain callbacks specified. */
		FMOD_ERR_UPDATE,                /* An error caused by System::update occured. */
		FMOD_ERR_VERSION,               /* The version number of this file format is not supported. */
		FMOD_ERR_PRELOADED,             /* The specified sound is still in use by the event system, call EventSystem::unloadFSB before trying to release it. */

		FMOD_ERR_EVENT_FAILED,          /* An Event failed to be retrieved, most likely due to 'just fail' being specified as the max playbacks behavior. */
		FMOD_ERR_EVENT_INFOONLY,        /* Can't execute this command on an EVENT_INFOONLY event. */
		FMOD_ERR_EVENT_INTERNAL,        /* An error occured that wasn't supposed to.  See debug log for reason. */
		FMOD_ERR_EVENT_MAXSTREAMS,      /* Event failed because 'Max streams' was hit when FMOD_EVENT_INIT_FAIL_ON_MAXSTREAMS was specified. */
		FMOD_ERR_EVENT_MISMATCH,        /* FSB mismatches the FEV it was compiled with, the stream/sample mode it was meant to be created with was different, or the FEV was built for a different platform. */
		FMOD_ERR_EVENT_NAMECONFLICT,    /* A category with the same name already exists. */
		FMOD_ERR_EVENT_NOTFOUND,        /* The requested event, event group, event category or event property could not be found. */
		FMOD_ERR_EVENT_NEEDSSIMPLE,     /* Tried to call a function on a complex event that's only supported by simple events. */
		FMOD_ERR_EVENT_GUIDCONFLICT,    /* An event with the same GUID already exists. */
		FMOD_ERR_EVENT_ALREADY_LOADED,  /* The specified project has already been loaded. Having multiple copies of the same project loaded simultaneously is forbidden. */

		FMOD_ERR_MUSIC_UNINITIALIZED,   /* Music system is not initialized probably because no music data is loaded. */

		FMOD_RESULT_FORCEINT = 65536    /* Makes sure this enum is signed 32bit. */
	};

	// Compared to regular FMOD_SOUND_TYPE ENUM from newer version, our version doesn't have the first enum value unknown. Removing it makes this enum match with the code in the IDB.
	enum FMOD_SOUND_TYPE{
		FMOD_SOUND_TYPE_UNKNOWN,         /* 3rd party / unknown plugin format. */
		FMOD_SOUND_TYPE_AAC,             /* AAC.  Currently unsupported. */
		FMOD_SOUND_TYPE_AIFF,            /* AIFF. */
		FMOD_SOUND_TYPE_ASF,             /* Microsoft Advanced Systems Format (ie WMA/ASF/WMV). */
		FMOD_SOUND_TYPE_AT3,             /* Sony ATRAC 3 format */
		FMOD_SOUND_TYPE_CDDA,            /* Digital CD audio. */
		FMOD_SOUND_TYPE_DLS,             /* Sound font / downloadable sound bank. */
		FMOD_SOUND_TYPE_FLAC,            /* FLAC lossless codec. */
		FMOD_SOUND_TYPE_FSB,             /* FMOD Sample Bank. */
		FMOD_SOUND_TYPE_GCADPCM,         /* GameCube ADPCM */
		FMOD_SOUND_TYPE_IT,              /* Impulse Tracker. */
		FMOD_SOUND_TYPE_MIDI,            /* MIDI. */
		FMOD_SOUND_TYPE_MOD,             /* Protracker / Fasttracker MOD. */
		FMOD_SOUND_TYPE_MPEG,            /* MP2/MP3 MPEG. */
		FMOD_SOUND_TYPE_OGGVORBIS,       /* Ogg vorbis. */
		FMOD_SOUND_TYPE_PLAYLIST,        /* Information only from ASX/PLS/M3U/WAX playlists */
		FMOD_SOUND_TYPE_RAW,             /* Raw PCM data. */
		FMOD_SOUND_TYPE_S3M,             /* ScreamTracker 3. */
		FMOD_SOUND_TYPE_SF2,             /* Sound font 2 format. */
		FMOD_SOUND_TYPE_USER,            /* User created sound. */
		FMOD_SOUND_TYPE_WAV,             /* Microsoft WAV. */
		FMOD_SOUND_TYPE_XM,              /* FastTracker 2 XM. */
		FMOD_SOUND_TYPE_XMA,             /* Xbox360 XMA */
		FMOD_SOUND_TYPE_VAG,             /* PlayStation 2 / PlayStation Portable adpcm VAG format. */

		FMOD_SOUND_TYPE_MAX,             /* Maximum number of sound types supported. */
		FMOD_SOUND_TYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
	};

	enum FMOD_SOUND_FORMAT{
		FMOD_SOUND_FORMAT_NONE,
		FMOD_SOUND_FORMAT_PCM8,
		FMOD_SOUND_FORMAT_PCM16,
		FMOD_SOUND_FORMAT_PCM24,
		FMOD_SOUND_FORMAT_PCM32,
		FMOD_SOUND_FORMAT_PCMFLOAT,
		FMOD_SOUND_FORMAT_BITSTREAM,
		FMOD_SOUND_FORMAT_MAX
	};

	enum FMOD_INITFLAGS : int
	{
		FMOD_INIT_NORMAL = 0x00000000,
		FMOD_INIT_STREAM_FROM_UPDATE = 0x00000001,
		FMOD_INIT_MIX_FROM_UPDATE = 0x00000002,
		FMOD_INIT_3D_RIGHTHANDED = 0x00000004,
		FMOD_INIT_CHANNEL_LOWPASS = 0x00000100,
		FMOD_INIT_CHANNEL_DISTANCEFILTER = 0x00000200,
		FMOD_INIT_PROFILE_ENABLE = 0x00010000,
		FMOD_INIT_VOL0_BECOMES_VIRTUAL = 0x00020000,
		FMOD_INIT_GEOMETRY_USECLOSEST = 0x00040000,
		FMOD_INIT_PREFER_DOLBY_DOWNMIX = 0x00080000,
		FMOD_INIT_THREAD_UNSAFE = 0x00100000,
		FMOD_INIT_PROFILE_METER_ALL = 0x00200000,
		FMOD_INIT_DISABLE_SRS_HIGHPASSFILTER = 0x00400000
	};

	extern inline FMOD_INITFLAGS operator|(FMOD_INITFLAGS a, FMOD_INITFLAGS b);

	enum FMOD_MODE : unsigned int
	{
		 FMOD_DEFAULT = 0x00000000,
		 FMOD_LOOP_OFF = 0x00000001,
		 FMOD_LOOP_NORMAL = 0x00000002,
		 FMOD_LOOP_BIDI = 0x00000004,
		 FMOD_2D = 0x00000008,
		 FMOD_3D = 0x00000010,
		 FMOD_CREATESTREAM = 0x00000080,
		 FMOD_CREATESAMPLE = 0x00000100,
		 FMOD_CREATECOMPRESSEDSAMPLE = 0x00000200,
		 FMOD_OPENUSER = 0x00000400,
		 FMOD_OPENMEMORY = 0x00000800,
		 FMOD_OPENMEMORY_POINT = 0x10000000,
		 FMOD_OPENRAW = 0x00001000,
		 FMOD_OPENONLY = 0x00002000,
		 FMOD_ACCURATETIME = 0x00004000,
		 FMOD_MPEGSEARCH = 0x00008000,
		 FMOD_NONBLOCKING = 0x00010000,
		 FMOD_UNIQUE = 0x00020000,
		 FMOD_3D_HEADRELATIVE = 0x00040000,
		 FMOD_3D_WORLDRELATIVE = 0x00080000,
		 FMOD_3D_INVERSEROLLOFF = 0x00100000,
		 FMOD_3D_LINEARROLLOFF = 0x00200000,
		 FMOD_3D_LINEARSQUAREROLLOFF = 0x00400000,
		 FMOD_3D_INVERSETAPEREDROLLOFF = 0x00800000,
		 FMOD_3D_CUSTOMROLLOFF = 0x04000000,
		 FMOD_3D_IGNOREGEOMETRY = 0x40000000,
		 FMOD_IGNORETAGS = 0x02000000,
		 FMOD_LOWMEM = 0x08000000,
		 FMOD_LOADSECONDARYRAM = 0x20000000,
		 FMOD_VIRTUAL_PLAYFROMSTART = 0x80000000
	};

	extern inline FMOD_MODE operator|(FMOD_MODE a, FMOD_MODE b);

	enum FMOD_CHANNELORDER {
		FMOD_CHANNELORDER_DEFAULT,
		FMOD_CHANNELORDER_WAVEFORMAT,
		FMOD_CHANNELORDER_PROTOOLS,
		FMOD_CHANNELORDER_ALLMONO,
		FMOD_CHANNELORDER_ALLSTEREO,
		FMOD_CHANNELORDER_ALSA,
		FMOD_CHANNELORDER_MAX
	};

	enum FMOD_CHANNELMASK : unsigned int
	{
		FMOD_CHANNELMASK_FRONT_LEFT = 0x00000001,
		FMOD_CHANNELMASK_FRONT_RIGHT = 0x00000002,
		FMOD_CHANNELMASK_FRONT_CENTER = 0x00000004,
		FMOD_CHANNELMASK_LOW_FREQUENCY = 0x00000008,
		FMOD_CHANNELMASK_SURROUND_LEFT = 0x00000010,
		FMOD_CHANNELMASK_SURROUND_RIGHT = 0x00000020,
		FMOD_CHANNELMASK_BACK_LEFT = 0x00000040,
		FMOD_CHANNELMASK_BACK_RIGHT = 0x00000080,
		FMOD_CHANNELMASK_BACK_CENTER = 0x00000100,
		FMOD_CHANNELMASK_MONO = (FMOD_CHANNELMASK_FRONT_LEFT),
		FMOD_CHANNELMASK_STEREO = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT),
		FMOD_CHANNELMASK_LRC = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER),
		FMOD_CHANNELMASK_QUAD = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_SURROUND_LEFT | FMOD_CHANNELMASK_SURROUND_RIGHT),
		FMOD_CHANNELMASK_SURROUND = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER | FMOD_CHANNELMASK_SURROUND_LEFT | FMOD_CHANNELMASK_SURROUND_RIGHT),
		FMOD_CHANNELMASK_5POINT1 = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER | FMOD_CHANNELMASK_LOW_FREQUENCY | FMOD_CHANNELMASK_SURROUND_LEFT | FMOD_CHANNELMASK_SURROUND_RIGHT),
		FMOD_CHANNELMASK_5POINT1_REARS = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER | FMOD_CHANNELMASK_LOW_FREQUENCY | FMOD_CHANNELMASK_BACK_LEFT | FMOD_CHANNELMASK_BACK_RIGHT),
		FMOD_CHANNELMASK_7POINT0 = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER | FMOD_CHANNELMASK_SURROUND_LEFT | FMOD_CHANNELMASK_SURROUND_RIGHT | FMOD_CHANNELMASK_BACK_LEFT | FMOD_CHANNELMASK_BACK_RIGHT),
		FMOD_CHANNELMASK_7POINT1 = (FMOD_CHANNELMASK_FRONT_LEFT | FMOD_CHANNELMASK_FRONT_RIGHT | FMOD_CHANNELMASK_FRONT_CENTER | FMOD_CHANNELMASK_LOW_FREQUENCY | FMOD_CHANNELMASK_SURROUND_LEFT | FMOD_CHANNELMASK_SURROUND_RIGHT | FMOD_CHANNELMASK_BACK_LEFT | FMOD_CHANNELMASK_BACK_RIGHT)
	};

	extern inline FMOD_CHANNELMASK operator|(FMOD_CHANNELMASK a, FMOD_CHANNELMASK b);

	enum FMOD_TIMEUNIT {
		FMOD_TIMEUNIT_MS = 0x00000001,
		FMOD_TIMEUNIT_PCM = 0x00000002,
		FMOD_TIMEUNIT_PCMBYTES = 0x00000004,
		FMOD_TIMEUNIT_RAWBYTES = 0x00000008,
		FMOD_TIMEUNIT_PCMFRACTION = 0x00000010,
		FMOD_TIMEUNIT_MODORDER = 0x00000100,
		FMOD_TIMEUNIT_MODROW = 0x00000200,
		FMOD_TIMEUNIT_MODPATTERN = 0x00000400
	};

	extern inline FMOD_TIMEUNIT operator|(FMOD_TIMEUNIT a, FMOD_TIMEUNIT b);
}

namespace Studio {

	enum FMOD_STUDIO_INITFLAGS : int
	{
		FMOD_STUDIO_INIT_NORMAL = 0x00000000,
		FMOD_STUDIO_INIT_LIVEUPDATE = 0x00000001,
		FMOD_STUDIO_INIT_ALLOW_MISSING_PLUGINS = 0x00000002,
		FMOD_STUDIO_INIT_SYNCHRONOUS_UPDATE = 0x00000004,
		FMOD_STUDIO_INIT_DEFERRED_CALLBACKS = 0x00000008,
		FMOD_STUDIO_INIT_LOAD_FROM_UPDATE = 0x00000010,
		FMOD_STUDIO_INIT_FORCE_INT = 0x10000000
	};

	extern inline FMOD_STUDIO_INITFLAGS operator|(FMOD_STUDIO_INITFLAGS a, FMOD_STUDIO_INITFLAGS b);

}