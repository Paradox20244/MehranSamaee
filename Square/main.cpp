#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ElementsBuffer.h"
#include "Window.h"
#include <stb/stb_image.h>
#include "Audio.h"

int main() {
	if (!glfwInit()) {
		MessageBox(NULL, L"Failed to initialize GLFW", L"Error", MB_ICONERROR | MB_OK);
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	Window MainWindow("Samaee The Teacher");

	if (!gladLoadGL()) {
		MessageBox(NULL, L"Failed to load OpenGL", L"Error", MB_ICONERROR | MB_OK);
		glfwTerminate();
		return -1;
	}
	glViewport(0, 0, MainWindow.DefaultWidth, MainWindow.DefaultHieght);

	glfwSetWindowSizeCallback(MainWindow.window, Resize_Callback);

	Shader ShaderProgram("Resources/Shaders/DefaultVertex.vert", "Resources/Shaders/DefaultFragment.frag");

	GLfloat Vertices[] = {
	  -1.0f,-1.0f,0.0f,   0.0f, 0.678f, 1.0f,  0.0f,0.0f,
	  -1.0f,1.0f,0.0f,    1.0f, 0.0f, 0.0f,    0.0f,1.0f,
	  1.0f,1.0f,0.0f,     1.0f, 0.984f, 0.0f,  1.0f,1.0f,
	  1.0f,-1.0f,0.0f,    0.0f, 1.0f, 0.016f,  1.0f,0.0f
	};

	GLuint indices[] = {
	   0,1,2,
	   0,3,2
	};

	VertexArray VertexArray1;
	VertexArray1.Bind();
	
	VertexBuffer VertexBuffer1(Vertices, sizeof(Vertices));
	ElementsBuffer ElementsBuffer1(indices, sizeof(indices));

	VertexArray1.LinkAttrib(VertexBuffer1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VertexArray1.LinkAttrib(VertexBuffer1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VertexArray1.LinkAttrib(VertexBuffer1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VertexArray1.Unbind();
	VertexBuffer1.Unbind();
	ElementsBuffer1.Unbind();

	int imgWidth, imgHieght, ColChannel;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* Image = stbi_load("Resources/Textures/Samaee(DEBUG).png", &imgWidth, &imgHieght, &ColChannel,0);

	GLuint Texture; glGenTextures(1, &Texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);

	// Image settings:

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHieght, 0, GL_RGBA, GL_UNSIGNED_BYTE, Image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(Image);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint TextureUniform0 = glGetUniformLocation(ShaderProgram.ID, "Texture0");
	ShaderProgram.Activate();
	glUniform1i(TextureUniform0, 0);

	Audio Babaii("Resources/Sounds/Babaii.wav");
	double FPSCap = 60.0;
	double TargetDelay = 1.0 / FPSCap;
	double LastFrameTime = glfwGetTime();

	while (!glfwWindowShouldClose(MainWindow.window)) {
		double CurrentTime = glfwGetTime();
		double Elapsed = CurrentTime - LastFrameTime;
		if (Elapsed >= TargetDelay) {
			LastFrameTime = CurrentTime;
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1, 1, 1, 1);
			ShaderProgram.Activate();
			glBindTexture(GL_TEXTURE_2D, Texture);
			VertexArray1.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glfwSwapBuffers(MainWindow.window);
			glfwPollEvents();
		}
		else {
			continue;
		}
	}

	VertexArray1.Delete();
	VertexBuffer1.Delete();
	glDeleteTextures(1,&Texture);
}