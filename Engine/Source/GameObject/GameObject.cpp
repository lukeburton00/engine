#include "GameObject.hpp"

void GameObject::addTransform()
{
	mTransform = std::make_shared<TransformComponent>(mId);
}

void GameObject::addSpriteRenderer()
{
	mSpriteComponent = std::make_shared<SpriteComponent>(mId);
}
