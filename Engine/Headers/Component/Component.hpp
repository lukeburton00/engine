#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "glm.hpp"
#include "Shader.hpp"

enum ComponentType
{
	renderComponent,
	transformComponent
};

struct Component
{
	int mId;
	int mParentObjectId;
	ComponentType mType;
};

struct RenderComponent : Component
{
	std::vector<GLfloat> mVertices;
	
	RenderComponent(int id)
	{
		mId = id;
		mType = renderComponent;
	}
	
	RenderComponent(int id, std::vector<GLfloat> vertices)
	{
		mId = id;
		mVertices = vertices;
		mType = renderComponent;
	}
};

struct TransformComponent : Component
{
	glm::vec3 mPosition;

	TransformComponent(int id)
	{
		mId = id;
		mPosition = glm::vec3(0,0,0);
		mType = transformComponent;
	}
	
	TransformComponent(int id, glm::vec3 position)
	{
		mId = id;
		mPosition = position;
		mType = transformComponent;
	}
};
