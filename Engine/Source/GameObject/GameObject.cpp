#include "GameObject.hpp"

void GameObject::addComponent(Component * pComponent)
{
    mComponents.push_back(pComponent);
}

void GameObject::removeComponent(Component * pComponent)
{
    mComponents.erase(remove(mComponents.begin(), mComponents.end(), pComponent));
}
