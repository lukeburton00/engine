#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
	bool isInitialized = false;
	
	/* ObjectManager tests */
	RenderSystem * pRenderer = &Renderer;
	objectManager = new ObjectManager(pRenderer);
	objectManager->createGameObject("GameObject1");
	
	auto renderComponent = objectManager->createRenderComponent("GameObject1");
	
	renderComponent->mVertices =
	{
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	
	
	/* ------------------- */
	
    if(!Renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, flags))
    {
        printf("ERROR: Unable to initialize renderer.");
    }
	
	isInitialized = true;
    return isInitialized;
}

void Application::Shutdown()
{
	delete objectManager;
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
}

void Application::Render()
{
    Renderer.Render();
}
