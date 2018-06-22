package com.Application.Acmen;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.AbsoluteLayout;

public class AcmenActivity extends Activity 
{

	private AcmenGLSurfaceView	mGLView;
	private AbsoluteLayout		mLayout;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		Log.d( "Acmen", "This is test " );
		AcmenJNI.TestJni( );
		mGLView = new AcmenGLSurfaceView(this);
		setContentView(mGLView);
	}

	@Override
	protected void onDestroy()
	{
		super.onDestroy();
	}

	@Override
	protected void onNewIntent(Intent intent)
	{
		super.onNewIntent(intent);
	}

	@Override
	protected void onPause() 
	{
		super.onPause();
	}

	@Override
	protected void onRestart()
	{
		super.onRestart();
	}

	@Override
	protected void onResume() 
	{
		super.onResume();
	}

	@Override
	protected void onStart()
	{
		super.onStart();
	}

	@Override
	protected void onStop()
	{
		super.onStop();
	}
}
