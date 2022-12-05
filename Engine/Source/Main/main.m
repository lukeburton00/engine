//
//  main.cpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//

#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_opengl.h"
#include "Application.hpp"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

int main(int argc, char* args[])
{
    static Application Engine;

    if(Engine.Initialize(SCREEN_WIDTH,SCREEN_HEIGHT, flags))
    {
        printf("Spinning up engine loop...\n\n");
        Engine.Run();
        printf("Engine loop ran nominally!\n\n");
    }

    else
    {
        printf( "Unable to initialize Engine!\n" );
    }

    Engine.Shutdown();

    return 0;
}
