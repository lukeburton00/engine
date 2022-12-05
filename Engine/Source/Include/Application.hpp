//
//  Application.hpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//
#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>
#include "InputSystem.hpp"
#include "Renderer.hpp"

using namespace std;

class Application
{
public:
    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Run();

private:
    bool isRunning;

    stringstream secondsText;
    stringstream framesText;
    stringstream framesPerSecondText;
    stringstream averagefpsText;
    Uint64 deltaTime;
    Uint64 elapsedTime;
    Uint64 seconds;
    Uint64 frames;
    Uint64 totalFrames;
    Uint64 totalElapsedTime;

    InputSystem Input;
    Renderer Renderer;


    void ProcessInput();
    void Update();
    void Render();
};
