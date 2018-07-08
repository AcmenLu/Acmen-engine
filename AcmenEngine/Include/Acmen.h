#pragma once

#include <algorithm> 
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw/glfw3.h>

#pragma comment( lib, "glfw3" )
#pragma comment( lib, "glew32s" )
#pragma comment( lib, "opengl32" )

// Common
#include "Common/Typedef.h"
#include "Common/Trace.h"
#include "Common/Math.h"
#include "Common/Vector2.h"
#include "Common/Vector3.h"
#include "Common/Vector4.h"
#include "Common/Matrix4.h"

// Renderer
#include "Renderer/Renderer.h"
#include "Renderer/Shader.h"

// Platform
//#include "Platform/System.h"
#include "Platform/Application.h"
#include "Platform/Windows.h"

// 2DUI

#include "2DUI/UINode.h"
#include "2DUI/UIScene.h"
#include "2DUI/UIDirector.h"

using namespace Acmen;
using namespace std;