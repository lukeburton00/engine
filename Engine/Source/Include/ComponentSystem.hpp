#pragma once
#include <stdio.h>
#include "Component/Component.hpp"

class ComponentSystem
{
public:
	std::vector<Component*> transformComponents;
	std::vector<Component*> physicsComponents;
	std::vector<RenderComponent*> renderComponents;
	std::vector<Component*> colliderComponents;
	std::vector<Component*> scriptComponents;


	void registerRenderComponent(RenderComponent * component);
	void disableComponent(Component * component, std::vector<Component*> componentVector);
};
