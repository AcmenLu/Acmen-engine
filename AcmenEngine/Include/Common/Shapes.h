#pragma once
namespace Acmen
{
class Shapes: public RenderObject
{
public:
	_bool	mIsReady;

public:
	inline Shapes( ): mIsReady( _false ){ }
	inline Shapes::Shapes( vector< Vertex > vertices, vector< _dword > indices )
		: RenderObject( vertices, indices ), mIsReady( _false ) { }
	inline ~Shapes( ) { };

	_bool CreateShader( );
	_bool SetUniform( );
	_void Update( _float elapse );
};
}