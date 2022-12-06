#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Component.hpp"

using namespace std;

class Entity
{
    public:
    int id;

    vector<Component*> components;

    void AddComponent(Component * component);
    void RemoveComponent(Component * component);
};
