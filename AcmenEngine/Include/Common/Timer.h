#pragma once
#include <time.h>

namespace Acmen
{
class Timer
{
private:
	clock_t mStart;
	clock_t mEnd;
	_double mElapse;

public:
	inline Timer( )
		:mStart( 0.0f ), mEnd( 0.0f ), mElapse( 0.0f ) { }
	inline ~Timer( ){ }
	_void Run( );
	_double GetElapse( );

};

}