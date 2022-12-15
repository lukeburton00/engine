#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Component.hpp"

class GameObject
{
public:
    int mId;
	std::string mName;
	std::vector<Component*> mComponents;
	
	GameObject(int pId, std::string pName)
	{
		mId = pId;
		mName = pName;
	}
	
	~GameObject()
	{
		for (int iComponent = 0; iComponent < mComponents.size(); iComponent++)
		{
			delete mComponents[iComponent];
		}
	}
	
	void addComponent(Component * component);
	void removeComponent(Component * component);
};
