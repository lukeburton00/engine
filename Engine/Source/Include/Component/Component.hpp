#pragma once

#include <iostream>
#include <vector>
#include "Shader.hpp"


struct Component
{
	int id;
};

struct RenderComponent : Component
{
	std::vector<GLfloat> vertices;
};
