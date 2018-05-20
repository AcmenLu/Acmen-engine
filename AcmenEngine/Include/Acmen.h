#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw/glfw3.h>

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
#include "Common/Material.h"
#include "Common/Mesh.h"

using namespace Acmen;
using namespace std;