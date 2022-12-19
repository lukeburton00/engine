#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Component.hpp"
#include <map>

class GameObject
{
public:
	int mId;
	std::string mName;
	
	GameObject(int id, std::string name)
	{
		mId = id;
		mName = name;
	}
	
	void addComponent(std::shared_ptr<Component> component);
	std::shared_ptr<Component> getComponent(ComponentType componentType);
	
private:
	std::map<ComponentType, std::shared_ptr<Component>> mComponents;
};
