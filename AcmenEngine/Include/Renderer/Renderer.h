#pragma once

namespace Acmen
{

class Renderer
{
public:
	static Renderer* sRenderer;
	static Renderer* GetInstance( );

public:
	vector<RenderObject*> mRenderList;

public:
	inline Renderer( ){ }
	inline ~Renderer( ){ }

	_void AddToRenderList( RenderObject* object );
	_void RemoveFromRenderList( RenderObject* object );
	_void ClearRenderList( );
	_void OnRender( _float elapse );
};


}