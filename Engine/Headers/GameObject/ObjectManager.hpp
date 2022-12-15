#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include "GameObject.hpp"

class ObjectManager
{
public:
	ObjectManager()
	{
		mGameObjectIdIncrement = 0;
		mComponentIdIncrement = 0;
	}
	GameObject createGameObject( std::string name );
	void removeGameObject( std::string name );
	
	RenderComponent createRenderComponent( std::string name );
	void removeComponent( std::string pName, Component * pComponent );
	GameObject getGameObject( std::string pName );
	
private:
	int mGameObjectIdIncrement;
	int mComponentIdIncrement;
	std::map<std::string, GameObject*> mGameObjects;
};
