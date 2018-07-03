#include "Acmen.h"

clock_t Timer::sStart = 0.0f;
clock_t Timer::sEnd = 0.0f;
_double Timer::sElapse = 0.0f;

_void Timer::Run( )
{
	sEnd = ::clock( );
	sElapse = sEnd - sStart;
	sStart = sEnd;
}

_double Timer::GetElapse()
{
	return sElapse;
}