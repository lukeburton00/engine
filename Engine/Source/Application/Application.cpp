//
//  Application.cpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//

#include "Application.hpp"

bool Application::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
    printf("\n\nInitializing engine...\n\n");
    bool isInitialized = true;

    if(!Renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, flags))
    {
        printf("ERROR: Unable to initialize renderer.");
    }

    printf("Engine has initialized! \n\n");

    //Tests


    isInitialized = true;
    return isInitialized;
}

void Application::Shutdown()
{
    printf("Quitting Engine...\n");

    Renderer.Shutdown();

    printf("Engine has shut down.\n\n");

    averagefpsText << totalFrames / totalElapsedTime;
    cout << "Average framerate: " << averagefpsText.str() << " frames per second." << endl;
}

void Application::Run()
{
    elapsedTime = 0;
    seconds = 0;
    frames = 0;
    totalFrames = 0;
    totalElapsedTime = 0;

    isRunning = true;

    Uint64 currentTime = SDL_GetTicks64();


    printf("Listening for input...\n\n");
    while (isRunning)
    {
        Uint64 previous = currentTime;
        ProcessInput();
        Update();
        Render();
        frames++;
        totalFrames++;
        currentTime = SDL_GetTicks64();
        deltaTime = currentTime - previous;
        elapsedTime += deltaTime;

        if (elapsedTime >= 1000)
        {
            //reduce elapsed time by 1 second
            elapsedTime -= 1000;

            //add 1 second to counter
            seconds++;
            totalElapsedTime++;

            //reset frames counter for next second
            frames = 0;
        }

        if (Input.quitEvent == true)
        {
            isRunning = false;
            break;
        }
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

    if (Input.IsKeyReleased("T"))
    {
        Renderer.LoadTriangle();
    }

    if (Input.IsKeyPressed("Escape"))
    {
        printf("Key Escape is pressed.\n");
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
