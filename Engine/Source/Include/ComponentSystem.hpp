#pragma once
#include <stdio.h>
#include "Component.hpp"

class ComponentSystem
{
public:
	vector<Component*> transformComponents;
	vector<Component*> physicsComponents;
	vector<Component*> spriteComponents;
	vector<Component*> colliderComponents;
	vector<Component*> scriptComponents;


	void registerComponent(Component * component, vector<Component> * componentVector);
};
