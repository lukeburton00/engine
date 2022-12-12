#pragma once

#include <iostream>
#include <vector>
#include "Math/Vector2.hpp"
#include "Render/Shader.hpp"


struct Component
{
	int id;
};

struct RenderComponent : Component
{
	std::vector<GLfloat> vertices;
};

struct TestComponent : Component
{
	Vector2 position;
};
