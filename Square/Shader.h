#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

std::string ReadShaderFiles(const char* FileName);

bool CheckCompilation(GLuint ShaderName);

class Shader {
public:
	GLuint ID;
	Shader(const char* VertexFile, const char* FragmentFile);
	void Activate();
	void Delete();
};

#endif