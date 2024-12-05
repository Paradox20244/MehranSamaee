#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &ID);
}

void VertexArray::LinkAttrib(VertexBuffer& TheVertexBuffer, GLuint layout, GLuint Numcomponenets, GLenum Type, GLuint Stride, void* offset) {
	TheVertexBuffer.Bind();
	glVertexAttribPointer(layout, Numcomponenets, Type, GL_FALSE ,Stride, offset);
	glEnableVertexAttribArray(layout);
	TheVertexBuffer.Unbind();
}

void VertexArray::Bind() {
	glBindVertexArray(ID);
}

void VertexArray::Unbind() {
	glBindVertexArray(0);
}

void VertexArray::Delete() {
	glDeleteVertexArrays(1,&ID);
}