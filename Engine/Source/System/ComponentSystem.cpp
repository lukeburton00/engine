#include "ComponentSystem.hpp"

void ComponentSystem::registerRenderComponent(RenderComponent * component)
{
	renderComponents.push_back(component);
}

void ComponentSystem::disableComponent(Component * component, std::vector<Component*> componentVector)
{
	if (count(componentVector.begin(), componentVector.end(), component))
	{
		componentVector.erase(remove(componentVector.begin(), componentVector.end(), component));
	}
	
	else
	{
		printf("Attempted to disable an unregistered component!");
	}
}

