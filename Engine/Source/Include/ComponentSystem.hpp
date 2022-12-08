#pragma once
#include <stdio.h>
#include "Component/Component.hpp"

class ComponentSystem
{
public:
	vector<Component*> transformComponents;
	vector<Component*> physicsComponents;
	vector<RenderComponent*> renderComponents;
	vector<Component*> colliderComponents;
	vector<Component*> scriptComponents;


	void registerRenderComponent(RenderComponent * component);
	void disableComponent(Component * component, vector<Component*> componentVector);
};
