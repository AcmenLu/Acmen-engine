#include "Acmen.h"

_bool Shapes::CreateShader( )
{
	if ( mVertices.size( ) <= 0 )
		return _false;

	string vsstr = "#version 330 core\n" \
		"layout (location = 0) in vec3 position;\n" \
		"layout (location = 1) in vec3 normal;\n" \
		"layout (location = 2) in vec2 texcoord;\n" \
		"out vec3 colors;\n" \
		"uniform mat4 model;\n" \
		"uniform mat4 view;\n" \
		"uniform mat4 projection;\n" \
		"void main()\n" \
		"{\n" \
		"colors = normal;\n" \
		"gl_Position = projection * view * model * vec4(position, 1.0);\n" \
		"}";

	string psstr = "#version 330 core\n" \
		"out vec4 FragColor;\n" \
		"in vec3 colors;\n" \
		"uniform sampler2D texture0;\n" \
		"void main()\n" \
		"{\n" \
		"FragColor = vec4(colors, 1.0);\n" \
		"}\n";
	mShader = new Shader( vsstr, psstr, _false );
	return _true;
}

_bool Shapes::SetUniform( )
{
	if ( mShader == _null )
		return _false;

	Matrix4 pro = Renderer::GetProjection3D( );
	Matrix4 view = Windows::GetInstance( )->GetRenderer( )->GetCamera( )->GetMatrix( );
	mShader->SetMatrix4( "projection", pro[0], _false );
	mShader->SetMatrix4( "view", view[0], _false );
	mShader->SetMatrix4( "model", mTransform[0], _false );
	return _true;
}

_void Shapes::Update( _float elapse )
{
	if ( mIsReady == _false )
	{
		InitRenderData( );
		mIsReady = _true;
	}
}