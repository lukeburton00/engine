#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
	bool isInitialized = false;
	
    if(!Renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, flags))
    {
        printf("ERROR: Unable to initialize renderer.");
    }
	
	else
	{
		isInitialized = true;
	}
	
    return isInitialized;
}

void Application::Shutdown()
{
    Renderer.Shutdown();
}

void Application::Run()
{
	isRunning = true;
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Application::ProcessInput()
{
    Input.ProcessInput();
}

void Application::Update()
{
	if (Input.IsKeyPressed("Escape"))
	{
		isRunning = false;
	}
	
	if (Input.IsKeyReleased("F"))
	{
		Renderer.toggleWireFrame();
	}
}

void Application::Render()
{
    Renderer.Render();
}
