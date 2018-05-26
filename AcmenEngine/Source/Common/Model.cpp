#include "Acmen.h"

Model::Model( const String& filename )
{
	LoadMeshsFromFile( filename );
}

_void Model::LoadMeshsFromFile( const String& filename )
{
	File file = File( );
	file.Open( filename, "r" );
	String* str = _null;
	while ( ( str = file.ReadLine( str ) ) != _null )
	{
		if ( String::StartWith( *str, "#" ) )
		{
			Trace::TraceString( "Strat with #" );
			continue;
		}
		else if ( String::StartWith( *str, "o" ) )
		{
			Trace::TraceString( "Strat with o" );
		}
		else if ( String::StartWith( *str, "v" ) )
		{
			Trace::TraceString( "Strat with v" );
		}
		else
		{
			Trace::TraceString( "Strat with Unknow" );
		}
	}
	file.Close( );
}