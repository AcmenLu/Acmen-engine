package com.Application.Acmen;

public class AcmenJNI
{
	static
	{
		System.loadLibrary( "Acmen" );
	}

	private native static int OnRender( );
	
	public static void Render( )
	{
		OnRender( );
	}
}
