#ifndef ELEMENTS_BUFFER_H
#define ELEMENTS_BUFFER_H

#include <glad/glad.h>

class ElementsBuffer
{
public:
	GLuint ID;
	ElementsBuffer(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
};

#endif