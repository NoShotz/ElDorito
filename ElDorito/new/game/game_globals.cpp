#include <ElDorito.hpp>
#include <game\game_globals.hpp>

namespace blam
{
	game_globals *__cdecl game_globals_get()
	{
		return *(blam::game_globals **)ElDorito::Instance().GetMainTls(0x3C);
	}
}