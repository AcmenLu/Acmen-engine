#pragma once

namespace Acmen
{

class String
{

public:
	_wchar*			mString;

public:
	inline String( )
		: mString( (_wchar*) L"" ){ }

	String( const _wchar* str );
	~String( );

};

};