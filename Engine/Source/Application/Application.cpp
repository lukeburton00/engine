#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
	bool isInitialized = false;
	
	/* ObjectManager tests */
	
	renderer.pObjectManager = &objectManager;
	
	GameObject object1 = objectManager.createGameObject("GameObject1");
	RenderComponent render1 = objectManager.createRenderComponent("GameObject1");
	
	render1.vertices =
	{
		0.0f, 0.5f, 0.0f, /* pos 1 */ 1.0f, 0.0f, 0.0f, /* color 1 */
		0.5f, -0.5f, 0.0f, /* pos 2 */ 0.0f, 1.0f, 0.f, /* color 2 */
		-0.5f, -0.5f, 0.0f, /* pos 3 */ 0.0f, 0.0f, 1.0f /* color 2 */
	};
	
	RenderComponent * pRender = &render1;
	renderer.addRenderComponent(pRender);
	
	/* ------------------- */
	
    if(!renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, flags))
    {
        printf("ERROR: Unable to initialize renderer.");
    }
	
	isInitialized = true;
    return isInitialized;
}

void Application::Shutdown()
{
    renderer.Shutdown();
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
    renderer.Render();
}
