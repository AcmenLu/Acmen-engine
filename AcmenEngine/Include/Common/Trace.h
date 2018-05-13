#pragma once

using namespace std;

namespace Acmen
{
	class Trace
	{
	public:
		inline Trace( )
			{ }
		inline ~Trace( )
			{ }
		inline static _void TraceString( string str )
			{ cout << str << endl; }
	};
};