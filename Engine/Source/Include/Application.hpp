#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>
#include "InputSystem.hpp"
#include "Render/RenderSystem.hpp"
#include "ComponentSystem.hpp"
#include "Entity.hpp"
#include "Component.hpp"

class Application
{
public:
    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Run();

private:
    bool isRunning;

    std::stringstream secondsText;
    std::stringstream framesText;
    std::stringstream framesPerSecondText;
    std::stringstream averagefpsText;
    Uint64 deltaTime;
    Uint64 elapsedTime;
    Uint64 seconds;
    Uint64 frames;
    Uint64 totalFrames;
    Uint64 totalElapsedTime;

    InputSystem Input;
    RenderSystem Renderer;
	ComponentSystem ComponentSys;
	
	std::vector<Entity> entities;
	std::vector<Component*> components;


    void ProcessInput();
    void Update();
    void Render();
	
	RenderComponent CreateComponent(int id, std::vector<GLfloat> vertices);
};
