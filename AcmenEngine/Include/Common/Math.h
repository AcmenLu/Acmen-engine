#pragma once

namespace Acmen
{

class Math
{
public:
	const static _float cPi;
public:
	static inline _float Radians( _float degree )
		{ return degree / 180.0f * cPi; }
	static inline _float Degree( _float radian )
		{ return radian / cPi * 180.0f; }

	static inline _float Sin( _float radian )
		{ return ::sinf( radian ); }

	static inline _float Cos( _float radian )
		{ return ::cosf( radian ); }

	static inline _float Tan( _float radian )
		{ return ::tanf( radian ); }
	static inline _float Cotan( _float radian )
		{ return 1.0f / ::tanf( radian ); }

	static inline _float Pow( _float n, _long e )
		{ return ::pow( n, e ); }
};
};