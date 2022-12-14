#include "GameObject.hpp"

void GameObject::addComponent(Component * component)
{
    components.push_back(component);
}

void GameObject::removeComponent(Component * component)
{
    components.erase(remove(components.begin(), components.end(), component));
}
