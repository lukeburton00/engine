#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "glm.hpp"
#include "Shader.hpp"

struct Component
{
	int id;
};

struct RenderComponent : Component
{
	std::vector<GLfloat> vertices;
};

struct PositionComponent : Component
{
	glm::vec3 position;

	PositionComponent(glm::vec3 position)
	{
		this->position = position;
	}
};
