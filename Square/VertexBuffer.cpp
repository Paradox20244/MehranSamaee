#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLfloat* Vertices,GLsizeiptr Size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, Size, Vertices, GL_STATIC_DRAW);
}

void VertexBuffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Delete() {
	glDeleteBuffers(1, &ID);
}