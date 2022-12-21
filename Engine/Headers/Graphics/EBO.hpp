#pragma once

#include <GL/glew.h>

class EBO
{
public:
	GLuint mId;
	
	EBO(GLuint * indices, GLsizeiptr size);
	
	void Bind();
	void Unbind();
	void Delete();
};
