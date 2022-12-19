#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include "GameObject.hpp"
#include "RenderSystem.hpp"

class ObjectManager
{
public:
	RenderSystem * mRenderer;
	ObjectManager(RenderSystem * renderer)
	{
		mRenderer = renderer;
		mGameObjectIdIncrement = 0;
	}
	
	std::shared_ptr<GameObject> createGameObject(std::string name);
	void removeGameObject(std::string name);
	
	std::shared_ptr<RenderComponent> createRenderComponent(std::string name);
	
	std::shared_ptr<GameObject> getGameObject(std::string name);
	std::shared_ptr<GameObject> getParentObject(std::shared_ptr<Component> component);
	
private:
	int mGameObjectIdIncrement;
	int mComponentIdIncrement;
	
	std::map<std::string, std::shared_ptr<GameObject>> mGameObjects;
};
