#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
	bool isInitialized = false;
	
	/* Component Creation/Rendering tests */
	std::vector<GLfloat> vertices =
	{
		0.0f, 0.5f, 0.0f, /* vPos1 */ 1.0f, 0.0f, 0.0f, /* vColor1 */
		-0.5f, -0.5f, 0.0f, /* vPos2 */ 0.0f, 1.0f, 0.0f, /* vColor2 */
		0.5f, -0.5f, 0.0f, /* vPos3 */ 0.0f, 0.0f, 1.0f /* vColor3 */
	};
	
	RenderComponent component = CreateComponent(1, vertices);
	RenderComponent * componentPointer;
	componentPointer = &component;
	
	ComponentSys.registerRenderComponent(componentPointer);
	
	Renderer.renderComponents = ComponentSys.renderComponents;
	
	/* ----------------- */
	
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

RenderComponent Application::CreateComponent(int id, std::vector<GLfloat> vertices)
{
	RenderComponent renderComponent;
	renderComponent.id = id;
	renderComponent.vertices = vertices;

	return renderComponent;
}
