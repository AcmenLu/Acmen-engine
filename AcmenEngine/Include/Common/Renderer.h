#pragma once

#include "Acmen.h"

namespace Acmen
{

class Renderer
{

public:
	vector<RenderObject*> mRenderList;

	Camera*			mCamera;
	glm::mat4		mProjection2D;
	glm::mat4		mProjection3D;

public:
	Renderer( );
	~Renderer( );

	inline Camera* GetCamera( )
		{ return mCamera; }
	inline glm::mat4 GetProjection2D( )
		{ return mProjection2D; }
	inline glm::mat4 GetProjection3D( )
		{ return mProjection3D; }

	_void ResetProjection( _float width, _float height );
	_void OnRender( _float elapse );
	_void ClearRenderList( );
	_void AddRenderObject( RenderObject* object );
	_void RemoveRenderObject( RenderObject* object );
};

};