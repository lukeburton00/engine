#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
	bool isInitialized = false;
	
	RenderComponent renderComponent;
	
	renderComponent.vertices =
	{
		0.0f,0.5f, 0.0f, /* vertex 1 */ 0.5f, 0.0f, 0.0f, /* color 1 */
		0.5f, -0.5f, 0.0f, /* vertex 2 */ 0.0f, 0.5f, 0.0f, /* color 2 */
		-0.5f, -0.5f, 0.0f, /* vertex 3 */ 0.0f, 0.0f, 0.5f /* color 3 */
	};
	
	renderComponent.id = 1;
	
	Renderer.addRenderComponent(&renderComponent);
	
	
    if(!Renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, flags))
    {
        printf("ERROR: Unable to initialize renderer.");
    }
	
	isInitialized = true;
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

    if (Input.IsKeyPressed("A"))
    {
        printf("Key A is pressed.\n");
    }

    if (Input.IsKeyPressed("S"))
    {
        printf("Key S is pressed.\n");
    }

    if (Input.IsKeyReleased("D"))
    {
        printf("Key D is was released.\n");
    }

    if (Input.IsKeyReleased("F"))
    {
        printf("Key F is was released.\n");
    }
	
	if (Input.IsKeyPressed("Escape"))
	{
		isRunning = false;
	}
}

void Application::Update()
{

}

void Application::Render()
{
    Renderer.Render();
}
