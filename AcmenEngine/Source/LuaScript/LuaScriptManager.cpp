#include "Acmen.h"
#include "lua.hpp"

//#pragma comment( lib, "luajit" )

_void LuaScriptManager::LoadScript( const String& filename )
{
	lua_State *L= luaL_newstate( );
	luaL_openlibs( L );
	luaL_loadfile( L, filename );
	lua_pcall( L, 0, 0, 0 );
	lua_close( L );
}