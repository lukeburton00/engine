#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>
#include "InputSystem.hpp"
#include "Renderer.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "../../Source/Component/testComponent.cpp"

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
	
	vector<Entity> entities;
	vector<Component*> components;


    void ProcessInput();
    void Update();
    void Render();
	
	
	



	Entity CreateEntity(int id);
	Component CreateComponent(int id);
	void AddComponentToEntity(Component& testComponent, Entity& entity);
	void UpdateTestEntityComponents(Entity& entity);
	void TestEntityComponentFramework();
};
