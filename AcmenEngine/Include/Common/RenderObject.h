#pragma once

namespace Acmen
{
class RenderObject
{
public:
	inline RenderObject( ){}
	inline ~RenderObject( ){}
	virtual inline void Render( ) = 0;
};

};