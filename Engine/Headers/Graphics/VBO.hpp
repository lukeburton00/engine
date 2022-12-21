#pragma once

#include <GL/glew.h>

class VBO
{
public:
	GLuint mId;
	
	VBO(GLfloat * vertices, GLsizeiptr size);
	
	void Bind();
	void Unbind();
	void Delete();
};
