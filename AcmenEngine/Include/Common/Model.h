#pragma once
namespace Acmen
{
class Model
{
public:
	vector< Mesh* > mMeshs;
public:
	Model( const String& filename );
	inline ~Model( )
		{ }

private:
	_void LoadMeshsFromFile( const String& filename );

};
};