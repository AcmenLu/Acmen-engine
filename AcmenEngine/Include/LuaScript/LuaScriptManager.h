#pragma once

namespace Acmen
{
class LuaScriptManager
{
public:
	inline LuaScriptManager( )
		{ }
	inline ~LuaScriptManager( )
		{ }
	_void LoadScript( const String& filename );
};
}