#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#define GLEW_STATIC
#include "glew.h"
#include "glfw3.h"
// Common
#include "Common/Typedef.h"
#include "Common/Trace.h"

#include "Common/Shader.h"
#include "Common/Texture.h"
#include "Common/RenderObject.h"
#include "Common/Camera.h"
#include "Common/Renderer.h"
#include "Common/Windows.h"


#include "Common/Spriter.h"


using namespace Acmen;
using namespace std;