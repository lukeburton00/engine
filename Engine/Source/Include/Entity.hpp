#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Component.hpp"

class Entity
{
public:
    int id;

    std::vector<Component*> components;

    void AddComponent(Component * component);
    void RemoveComponent(Component * component);
};
