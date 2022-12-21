#include "VAO.hpp"

VAO::VAO()
{
	glGenVertexArrays(1, &mId);
}

void VAO::LinkVBO(VBO VBO, GLuint layout)
{
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(layout);
}

void VAO::Bind()
{
	glBindVertexArray(mId);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &mId);
}
