//
//  Component.hpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Component
{
    public:
        int id;
        virtual void Update() = 0;
};
