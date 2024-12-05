#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>
#include "VertexBuffer.h"

class VertexArray
{
public:
	GLuint ID;
	VertexArray();
	void LinkAttrib(VertexBuffer& TheVertexBuffer, GLuint layout, GLuint Numcomponenets, GLenum Type, GLuint Stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};

#endif