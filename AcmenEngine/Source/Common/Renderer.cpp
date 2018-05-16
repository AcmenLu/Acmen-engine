
#include "Acmen.h"

Renderer::Renderer( )
{
	mCamera = new Camera( );
	ResetProjection( _float( Windows::GetInstance( )->mWidth ), Windows::GetInstance( )->mHeight );
}

Renderer::~Renderer( )
{
	if ( mCamera != _null )
	{
		mCamera->~Camera( );
		delete mCamera;
	}
}

_void Renderer::ResetProjection( _float width, _float height )
{
	mProjection3D = glm::perspective( glm::radians( 60.0f ), width / height, 0.1f, 100.0f );
	mProjection2D = glm::ortho( 0.0f, width, height, 0.0f, -1.0f, 1.0f );
}

_void Renderer::OnRender( _float elapse )
{
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
		mRenderList[i]->Render( );
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