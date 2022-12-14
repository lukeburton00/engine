#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Component.hpp"
#include <string>

class GameObject
{
public:
	std::string name;
    int id;

    std::vector<Component*> components;
    void addComponent(Component * component);
    void removeComponent(Component * component);
};
