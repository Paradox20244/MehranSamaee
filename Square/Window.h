#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
	GLFWwindow* window;
	GLFWmonitor* TheMonitor;
	const GLFWvidmode* MonitorMode;
	GLuint DefaultWidth;
	GLuint DefaultHieght;
	GLfloat WindowX;
	GLfloat WindowY;
	Window(const char* WindowName);
	void Destroy();
};

void Resize_Callback(GLFWwindow* Window, int width, int hieght);

#endif