#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "glm.hpp"
#include "Shader.hpp"

enum componentType
{
	renderComponent,
	positionComponent
};

struct Component
{
	int id;
	int parentGameObject;
	componentType type;
};

struct RenderComponent : Component
{
	std::vector<GLfloat> vertices;
	
	RenderComponent(int id, int parentId)
	{
		this->id = id;
		this->parentGameObject = parentId;
		this->type = renderComponent;
	}
	
	RenderComponent(int id, std::vector<GLfloat> vertices)
	{
		this->id = id;
		this->vertices = vertices;
		this->type = renderComponent;
	}
};

struct PositionComponent : Component
{
	glm::vec3 position;

	PositionComponent(int id, int parentId)
	{
		this->id = id;
		this->parentGameObject = parentId;
		this->position = glm::vec3(0,0,0);
		this->type = positionComponent;
	}
	
	PositionComponent(int id, int parentId, glm::vec3 position)
	{
		this->id = id;
		this->parentGameObject = parentId;
		this->position = position;
		this->type = positionComponent;
	}
};
