
#include "Acmen.h"

Matrix4 Renderer::GetProjection2D( )
{
	return Matrix4::CreateOrthoRH( (_float)(Windows::GetInstance( )->GetWidth( ) ), (_float)( Windows::GetInstance( )->GetHeight( ) ), -1.0f, 1.0f );
}

Matrix4 Renderer::GetProjection3D( )
{
	return Matrix4::CreatePerspectiveFovRH( Math::Radians( 60.0f ), (_float)(Windows::GetInstance( )->GetWidth( ) ) / (_float)( Windows::GetInstance( )->GetHeight( ) ), 0.1f, 100.0f );
}

Renderer::~Renderer( )
{
	if ( mCamera != _null )
		delete mCamera;

	mCamera = _null;
}

_void Renderer::OnRender( _float elapse )
{
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
	{
		mRenderList[i]->Update( elapse );
		mRenderList[i]->Render( elapse );
	}
}

_void Renderer::ClearRenderList( )
{
	for ( _dword i = mRenderList.size( ) - 1; i >= 0 ; i-- )
	{
		RenderObject* object = mRenderList[i];
		mRenderList.pop_back( );
		object->~RenderObject( );
	}
}

_void Renderer::AddRenderObject( RenderObject* object )
{
	_bool isAtList = _false;
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
	{
		if ( object == mRenderList[i] )
			isAtList = _true;
	}

	if ( isAtList == _false )
		mRenderList.push_back( object );
}

_void Renderer::RemoveRenderObject( RenderObject* object )
{
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
	{
		if ( object == mRenderList[i] )
			mRenderList.erase( mRenderList.begin( ) + i );
	}
}