package com.Application.Acmen;

public class AcmenJNI
{
	static
	{
		System.loadLibrary( "Acmen" );
	}
	
	private native static int PrintStr( String str );
	
	public static void TestJni( )
	{
		PrintStr( "test" );
	}
}
