#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>
#include "ObjectManager.hpp"
#include "InputSystem.hpp"
#include "RenderSystem.hpp"
#include "GameObject.hpp"
#include "Component.hpp"

class Application
{
public:
	bool isRunning;
    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Run();

private:
	ObjectManager objectManager;
    InputSystem Input;
	RenderSystem renderer;

    void ProcessInput();
    void Update();
    void Render();
};
