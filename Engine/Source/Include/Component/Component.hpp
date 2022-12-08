#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "Math/Vector2.hpp"

using namespace std;

struct Component
{
	int id;
};

struct RenderComponent : Component
{
	const GLchar * vertexSource;
	const GLchar * fragmentSource;
	GLuint vertexDataSize;
	vector<GLfloat> vertices;
};

struct TestComponent : Component
{
	Vector2 position;
};
