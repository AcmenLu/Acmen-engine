#pragma once

#include "Acmen.h"

namespace Acmen
{

class Renderer
{

public:
	vector<RenderObject*> mRenderList;

	Camera*			mCamera;

public:
	static glm::mat4 GetProjection2D( );
	static glm::mat4 GetProjection3D( );

public:
	Renderer( )
		: mCamera( new Camera( ) ){ }
	~Renderer( );

	inline Camera* GetCamera( )
		{ return mCamera; }

	_void OnRender( _float elapse );
	_void ClearRenderList( );
	_void AddRenderObject( RenderObject* object );
	_void RemoveRenderObject( RenderObject* object );
};

};