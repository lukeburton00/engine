#include "GameObject.hpp"

std::shared_ptr<Component> GameObject::getComponent(ComponentType componentType)
{
	// Check if component of type exists
	if (mComponents.count(componentType) == 0)
	{
		// Warn command user of nullptr in case of no component
		printf("WARNING: No component of type %d on GameObject %s. NULLPTR returned.", componentType, mName.c_str());
		return nullptr;
	}
	
	// Get component of type by type reference
	return mComponents[componentType];
}

void GameObject::addComponent(std::shared_ptr<Component> component)
{
	mComponents[component->mType] = component;
}
