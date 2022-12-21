#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "glm.hpp"
#include "Shader.hpp"
#include "Texture2D.hpp"

class Component
{
public:
	int mParentObjectId;
};

class SpriteComponent : Component
{
public:
	int mSpriteID;
	
	SpriteComponent(int id)
	{
		mParentObjectId = id;
	}
};

class TransformComponent : Component
{
public:
	glm::vec3 mPosition;

	TransformComponent(int id)
	{
		mParentObjectId = id;
		mPosition = glm::vec3(0,0,0);
	}
	
	TransformComponent(int id, glm::vec3 position)
	{
		mParentObjectId = id;
		mPosition = position;
	}
};
