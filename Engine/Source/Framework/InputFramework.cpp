//
//  InputFramework.cpp
//  Engine
//
//  Created by Luke Burton on 12/5/22.
//

#include "InputFramework.hpp"

void InputFramework::handleKeyboardEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
            {
                addPressedKey(SDL_GetKeyName(event.key.keysym.sym));
                break;
            }

            case SDL_KEYUP:
            {
                addReleasedKey(SDL_GetKeyName(event.key.keysym.sym));
                break;
            }

            case SDL_QUIT:
            {
                break;
            }

            default:
            {
                break;
            }
        }
    }
}

void InputFramework::addPressedKey(const char * key)
{
    pressedKeys.push_back(key);
}

void InputFramework::addReleasedKey(const char * key)
{
    releasedKeys.push_back(key);
}
