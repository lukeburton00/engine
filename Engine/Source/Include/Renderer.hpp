#pragma once
#define GLEW_STATIC

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"

using namespace std;

class Renderer
{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext glContext;

    bool Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags);
    void Shutdown();
    void Render();

    void LoadTriangle();
    
private:
    void CreateVertexBufferObject(float vertexArray[]);
    void CreateVertexArrayObject();
    GLuint CreateVertexShader( const GLchar * vertexShaderSource);
    GLuint CreateFragmentShader( const GLchar * fragmentShaderSource);
    GLuint CreateProgram(GLuint vertexShader, GLuint fragmentShader);

};
