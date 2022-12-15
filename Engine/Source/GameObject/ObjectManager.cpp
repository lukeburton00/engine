#include "ObjectManager.hpp"

GameObject ObjectManager::createGameObject(std::string name)
{
	GameObject * object = new GameObject(mGameObjectIdIncrement, name);
	mGameObjects[name] = object;
	return *object;
}

void ObjectManager::removeGameObject(std::string name)
{
	delete mGameObjects[name];
}

RenderComponent ObjectManager::createRenderComponent(std::string name)
{
	RenderComponent * component = new RenderComponent(mComponentIdIncrement, mGameObjectIdIncrement);
	
	mGameObjects[name]->addComponent(component);
	
	return *component;
}

void ObjectManager::removeComponent(std::string name, Component * pComponent)
{
	mGameObjects[name]->removeComponent(pComponent);
}

GameObject ObjectManager::getGameObject(std::string name)
{
	return *mGameObjects[name];
}
