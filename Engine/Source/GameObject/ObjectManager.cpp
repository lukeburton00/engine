#include "ObjectManager.hpp"

std::shared_ptr<GameObject> ObjectManager::createGameObject(std::string name)
{
	// Create gameObject and assign to a pointer
	std::shared_ptr<GameObject> object = std::make_shared<GameObject>(mGameObjectIdIncrement, name);
	
	// Map gameObject to its name
	mGameObjects[name] = object;
	
	// Auto-increment object ID
	mGameObjectIdIncrement++;
	
	return object;
}

void ObjectManager::removeGameObject(std::string name)
{
	// Remove object pointer from map by name reference
	mGameObjects.erase(name);
}

std::shared_ptr<RenderComponent> ObjectManager::createRenderComponent(std::string name)
{
	// Create component and assign to a pointer
	std::shared_ptr<RenderComponent> component = std::make_shared<RenderComponent>(mComponentIdIncrement);
	
	// Give component to parent gameObject
	mGameObjects[name]->addComponent(component);
	
	// Assign parent ID in component
	component->mParentObjectId = mGameObjects[name]->mId;
	
	return component;
}

std::shared_ptr<GameObject> ObjectManager::getGameObject(std::string name)
{
	// Get pointer to gameObject by name reference
	// This allows other scripts to manipulate gameObject
	return mGameObjects[name];
}
