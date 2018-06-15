#include "Acmen.h"

_bool String::StartWith( const string& srcstr, const string& pattern )
{
	if ( srcstr.size( ) < pattern.size( ) )
		return _false;

	return srcstr.find( pattern, 0 ) == 0;
}

_dword String::StrToDword( const string& srcstr )
{
	return ::atoi( srcstr.c_str( ) );
}

_float String::StrToFloat( const string& srcstr )
{
	return ::atof( srcstr.c_str( ) );
}

vector<string> String::Split( const string& srcstr, const string& pattern )
{
	vector<string> tmp;
	_long pos = 0;
	string str = srcstr + pattern;
	while ( ( pos = str.find( pattern, 0 ) ) != string::npos )
	{
		string s = str.substr( 0, pos );
		if ( s.size( ) > 0 )
			tmp.push_back( s );
		str = str.substr( pos + 1, str.size( ) );
	}

	return tmp;
}

string String::TrimWith( string& srcstr, const string& pattern )
{
	if ( !srcstr.empty( ) )
	{
		srcstr.erase( 0, srcstr.find_first_not_of( pattern ) );
		srcstr.erase( srcstr.find_last_not_of( pattern ) + 1 );
	}
	return srcstr;
}