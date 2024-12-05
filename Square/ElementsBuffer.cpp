#include "ElementsBuffer.h"

ElementsBuffer::ElementsBuffer(GLuint* indices, GLsizeiptr size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ElementsBuffer::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
}

void ElementsBuffer::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementsBuffer::Delete() {
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &ID);
}