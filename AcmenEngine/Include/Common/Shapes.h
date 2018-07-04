#pragma once
namespace Acmen
{
class Shapes: public RenderObject
{

public:
	inline Shapes( ){ }
	inline Shapes::Shapes( vector< Vertex > vertices, vector< _dword > indices )
		: RenderObject( vertices, indices ) { }
	inline ~Shapes( ) { };

	_bool CreateShader( );
	_bool SetUniform( );
	_void Render( _float elapse );
};
}