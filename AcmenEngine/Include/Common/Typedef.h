#pragma once
namespace Acmen
{

#define _null		0
#define _true		1
#define _false		0

typedef unsigned int	_dword;
typedef int				_long;
typedef float			_float;
typedef void			_void;
typedef bool			_bool;
typedef double			_double;

typedef char			_char;
typedef unsigned char	_chara;
typedef wchar_t			_wchar;


#define SAFE_RELESE( t ) \
{ \
	if ( t != _null ) \
		delete t; \
	t = _null; \
}

};