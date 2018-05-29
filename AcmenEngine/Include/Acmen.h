#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw/glfw3.h>

// Common
#include "Common/Typedef.h"
#include "Common/Trace.h"
#include "Common/Math.h"
#include "Common/String.h"
#include "Common/File.h"

#include "Common/Vector2.h"
#include "Common/Vector3.h"
#include "Common/Vector4.h"
#include "Common/Matrix4.h"

#include "Common/Shader.h"
#include "Common/Texture.h"
#include "Common/RenderObject.h"
#include "Common/Camera.h"
#include "Common/Renderer.h"
#include "Common/Windows.h"

#include "Common/Spriter.h"
#include "Common/Material.h"
#include "Common/Mesh.h"
#include "Common/Model.h"

#include "LuaScript/LuaScriptManager.h"

using namespace Acmen;
using namespace std;