#pragma once

#include <iostream>
#include <stdio.h>
#include "Component.hpp"

class GameObject
{
public:
	
	// Identifiers
	int mId;
	std::string mName;
	
	// Components
	std::shared_ptr<TransformComponent> mTransform = nullptr;
	std::shared_ptr<SpriteComponent> mSpriteComponent = nullptr;
	
	GameObject(int id, std::string name)
	{
		mId = id;
		mName = name;
	}
	
	void addTransform();
	void addSpriteRenderer();
};
