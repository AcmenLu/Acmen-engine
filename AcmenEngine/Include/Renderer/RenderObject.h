#pragma once

namespace Acmen
{

class RenderObject
{

public:
	inline RenderObject( ){ }
	inline ~RenderObject( ) { }

	virtual _void OnRender( _float elapse ) = 0;

};

}