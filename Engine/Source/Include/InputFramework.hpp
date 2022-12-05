//
//  InputFramework.hpp
//  Engine
//
//  Created by Luke Burton on 12/5/22.
//
#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>

class InputFramework
{
    
public:
    bool isKeyDown();
    bool isKeyUp();
    
private:
    std::vector<const char *> pressedKeys;
    std::vector<const char *> releasedKeys;
    
    void handleKeyboardEvent();
    
    void addPressedKey(const char *);
    void addReleasedKey(const char *);
    
    void removePressedKey(const char *);
    void removeReleasedKey(const char *);
};
