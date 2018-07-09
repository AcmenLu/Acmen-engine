#include "Acmen.h"

_void Timer::Run( )
{
	mEnd = ::clock( );
	mElapse = mEnd - mStart;
	mStart = mEnd;
}

_double Timer::GetElapse()
{
	return mElapse;
}