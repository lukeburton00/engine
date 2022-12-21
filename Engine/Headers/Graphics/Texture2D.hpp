#pragma once
#include <GL/glew.h>
#include <iostream>
#include "stb_image.hpp"

class Texture2D
{
public:
	GLuint mId;
	Texture2D(const char * texturePath);
	void bind();
};
