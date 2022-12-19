#pragma once
#define GLEW_STATIC
#include "Shader.hpp"
#include "Component.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"
#include <iostream>
#include <string>
#include <vector>
#include "stb_image.hpp"
#include "Observer.hpp"

class RenderSystem
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;
	
	bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
	void Render();
};
