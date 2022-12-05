//
//  Entity.cpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//

#include "Entity.hpp"

void Entity::AddComponent(Component * component)
{
    components.push_back(component);
}

void Entity::RemoveComponent(Component * component)
{
    components.erase(remove(components.begin(), components.end(), component));
}

void Entity::UpdateComponents()
{
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->Update();
    }
}
