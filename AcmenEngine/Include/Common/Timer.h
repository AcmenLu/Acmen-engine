#pragma once
#include <time.h>

namespace Acmen
{
class Timer
{
public:
	static clock_t sStart;
	static clock_t sEnd;
	static _double sElapse;

public:
	inline Timer( ){ }
	inline ~Timer( ){ }
	static _void Run( );
	static _double GetElapse( );

};

}