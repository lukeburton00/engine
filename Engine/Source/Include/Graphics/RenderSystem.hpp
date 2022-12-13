#pragma once
#define GLEW_STATIC

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"
#include "ComponentSystem.hpp"
#include "Shader.hpp"

class RenderSystem
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;
	
	std::vector<RenderComponent*> renderComponents;
	std::vector<GLuint> VAOs;
	std::vector<Shader> shaders;
	void addShader(Shader shader);


    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Render();
	
    
private:
	
	void buildVAO(RenderComponent * renderComponent);
	void Draw(GLuint VAO, Shader shader);

};
