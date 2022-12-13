#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>
#include "InputSystem.hpp"
#include "RenderSystem.hpp"
#include "ComponentSystem.hpp"
#include "Entity.hpp"
#include "Component.hpp"

class Application
{
public:
	bool isRunning;
    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Run();

private:
	
    InputSystem Input;
    RenderSystem Renderer;
	ComponentSystem ComponentSys;

    void ProcessInput();
    void Update();
    void Render();
	
	RenderComponent CreateComponent(int id, std::vector<GLfloat> vertices);
};
