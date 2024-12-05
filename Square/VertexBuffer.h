#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

class VertexBuffer
{
public:
	GLuint ID;
	VertexBuffer(GLfloat* Vertices, GLsizeiptr Size);
	void Bind();
	void Unbind();
	void Delete();
};

#endif