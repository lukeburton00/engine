#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include "GameObject.hpp"

class ObjectManager
{
public:
	void addGameObject(GameObject * pObject, std::string name);
	void removeGameObject(std::string name);
	GameObject getGameObject(std::string name);
	
private:
	std::map< std::string, GameObject* > mGameObjects;
};
