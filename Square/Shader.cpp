#include "Shader.h"

std::string ReadShaderFiles(const char* FileName) {
	std::ifstream input(FileName, std::ios::binary);
	if (input) {
		std::string ShaderContents;
		input.seekg(0, std::ios::end);
		ShaderContents.resize(input.tellg());
		input.seekg(0, std::ios::beg);
		input.read(&ShaderContents.at(0), ShaderContents.size());
		input.close();
		return(ShaderContents);
	}
	else {
		return "fail";
	}
}

bool CheckCompilation(GLuint ShaderName) {
	GLint result;

	glGetShaderiv(ShaderName, GL_COMPILE_STATUS, &result);

	if (!result) {
		return false;
	}
	else {
		return true;
	}
}

Shader::Shader(const char* VertexFile, const char* FragmentFile) {
	std::string VertexCode = ReadShaderFiles(VertexFile);
	std::string FragmentCode = ReadShaderFiles(FragmentFile);
	if (VertexCode == "fail" || FragmentCode == "fail") {
		MessageBox(NULL, L"Failed to load shader files", L"Error", MB_ICONERROR | MB_OK);
		exit(-1);
	}
	const char* VertexSource = VertexCode.c_str();
	const char* FragmentSource = FragmentCode.c_str();

	GLuint VertexShader, FragmentShader;
	GLint exitcode = 0;
     
	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1,&VertexSource,NULL);
	glCompileShader(VertexShader);
	if (!CheckCompilation(VertexShader)) {
		MessageBox(NULL, L"Shader of type Vertex compilation failure", L"Compilation Error", MB_OK | MB_ICONERROR);
		exitcode = -1;
	}

	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader,1, &FragmentSource,NULL);
	glCompileShader(FragmentShader);
	if (!CheckCompilation(FragmentShader)) {
		MessageBox(NULL, L"Shader of type Fragment compilation failure", L"Compilation Error", MB_OK | MB_ICONERROR);
		exitcode = -1;
	}
	
	if (exitcode != 0) {
		exit(exitcode);
	}

	ID = glCreateProgram();
	glAttachShader(ID, VertexShader);
	glAttachShader(ID, FragmentShader);
	glLinkProgram(ID);
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);
}