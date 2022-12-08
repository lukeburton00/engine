#pragma once
#define GLEW_STATIC

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"
#include "ComponentSystem.hpp"


using namespace std;

class RenderSystem
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;
	
	vector<RenderComponent*> renderComponents;
	vector<GLuint> VAOs;
	vector<GLuint> shaderPrograms;

    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Render();
	
    
private:
	
	GLuint buildVAO(RenderComponent * renderComponent);
	GLuint buildShaderProgram(RenderComponent * renderComponent);
	
	void buildAllVAOs();
	void buildAllShaderPrograms();
	
	void Draw(GLuint VAO, GLuint shaderProgram);

};
