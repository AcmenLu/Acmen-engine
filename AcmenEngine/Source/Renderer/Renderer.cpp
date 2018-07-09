#include "Acmen.h"

Renderer* Renderer::sRenderer = _null;
Renderer* Renderer::GetInstance( )
{
	if ( sRenderer == _null )
		sRenderer = new Renderer( );

	return sRenderer;
}

_void Renderer::AddToRenderList( RenderObject* object )
{
	vector<RenderObject*>::iterator iter = find( mRenderList.begin( ), mRenderList.end( ), object );
	if ( iter != mRenderList.end( ) )
		mRenderList.push_back( object );
}

_void Renderer::RemoveFromRenderList( RenderObject* object )
{
	vector<RenderObject*>::iterator iter = find( mRenderList.begin( ), mRenderList.end( ), object );
	if ( iter != mRenderList.end( ) )
		mRenderList.erase( iter );
}

_void Renderer::ClearRenderList( )
{
	mRenderList.clear( );
}

_void Renderer::OnRender( _float elapse )
{
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	for ( RenderObject* object : mRenderList )
		object->OnRender( elapse );

	ClearRenderList( );
}