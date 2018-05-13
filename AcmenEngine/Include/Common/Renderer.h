#pragma once

#include "Acmen.h"

namespace Acmen
{

class Renderer
{

public:
	vector<RenderObject*> mRenderList;

	inline Renderer( )
		{ }
	inline ~Renderer( )
		{ }

	void OnRender( _float elapse );
	void ClearRenderList( );
	void AddRenderObject( RenderObject* object );
	void RemoveRenderObject( RenderObject* object );
};

};