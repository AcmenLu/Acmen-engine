#pragma once

namespace Acmen
{

class String
{
public:
	static _bool StartWith( const string& srcstr, const string& desstr );
	static _dword StrToDword( const string& srcstr );
	static _float StrToFloat( const string& srcstr );
	static vector<string> Split( const string& srcstr, const string& pattern );
	static string TrimWith( string& srcstr, const string& pattern );
};
}