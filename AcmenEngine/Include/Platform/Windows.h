#pragma once

namespace Acmen
{

class Windows
{

private:
	GLFWwindow*			mGLFWWindow;

public:
	Windows( );
	Windows( _float w, _float h );
	~Windows( );

	_float GetWidth( );
	_float GetHeight( );

	_void ReSize( _float width, _float height );
	_void Run( );
	_void Close( );

private:
	_void initWindows( _float width, _float height );
};

}