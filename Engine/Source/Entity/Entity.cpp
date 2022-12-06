#include "Entity.hpp"

void Entity::AddComponent(Component * component)
{
    components.push_back(component);
}

void Entity::RemoveComponent(Component * component)
{
    components.erase(remove(components.begin(), components.end(), component));
}
