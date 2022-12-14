#include "ObjectManager.hpp"

void ObjectManager::addGameObject(GameObject * pObject, std::string name)
{
	mGameObjects[name] = pObject;
}

void ObjectManager::removeGameObject(std::string name)
{
	mGameObjects.erase(name);
}

GameObject ObjectManager::getGameObject(std::string name)
{
	return *mGameObjects[name];
}

