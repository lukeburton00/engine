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
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class RenderSystem
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;
	
	GLuint vertexArrayObject;
	GLuint quadShader;
	GLuint quadTexture;
	
	bool wireFrameEnabled = false;
	
	bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
	void Render();
	void prepareQuad();
	void toggleWireFrame();
};
