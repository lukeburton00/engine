#pragma once
#define GLEW_STATIC
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"
#include "Shader.hpp"
#include "Component.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "stb_image.hpp"

class RenderSystem
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;

	void addRenderComponent(RenderComponent * renderComponent);
	void removeRenderComponent(RenderComponent * renderComponent);
	void addShader(Shader shader);
	
	void handleTexture();
	
	bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Render();
    
private:
	std::vector<RenderComponent*> renderComponents;
	std::vector<GLuint> VAOs;
	std::vector<Shader> shaders;
	
	void buildVAO(RenderComponent * renderComponent);
	void Draw(GLuint VAO, Shader shader);
};
