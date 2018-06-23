package com.Application.Acmen;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.Log;

public class AcmenGLSurfaceView extends GLSurfaceView
{
	AcmenRenderer mRenderer;

	public class AcmenRenderer implements GLSurfaceView.Renderer
	{
		@Override
		public void onDrawFrame(GL10 gl)
		{
			Log.d("Acmen", "onIdle");
			AcmenJNI.Render( );
		}

		@Override
		public void onSurfaceChanged(GL10 gl, int width, int height)
		{
		
		}

		@Override
		public void onSurfaceCreated(GL10 gl, EGLConfig config)
		{
			
		}
	}

	@Override
	public void onPause()
	{
		super.onPause();
	}

	@Override
	public void onResume()
	{
		super.onResume();
	}

	public AcmenGLSurfaceView(Context context)
	{
		super(context);
		mRenderer = new AcmenRenderer( );
		this.setRenderer( mRenderer );
	}
}
