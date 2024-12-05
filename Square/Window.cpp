#include "Window.h"

Window::Window(const char* WindowName) {
	TheMonitor = glfwGetPrimaryMonitor();
	MonitorMode = glfwGetVideoMode(TheMonitor);
	DefaultWidth = 1000;
	DefaultHieght = 600;
	WindowX = (MonitorMode->width - DefaultWidth) / 2;
	WindowY = (MonitorMode->height - DefaultHieght) / 2;
	glfwWindowHint(GLFW_POSITION_X, WindowX);
	glfwWindowHint(GLFW_POSITION_Y, WindowY);
	std::cout << "Set WindowX is " << WindowX << std::endl;
	std::cout << "Set WindowY is " << WindowY << std::endl;
	window = glfwCreateWindow(DefaultWidth, DefaultHieght,WindowName, NULL, NULL);
	glfwMakeContextCurrent(window);
}

void Resize_Callback(GLFWwindow* Window,int width,int hieght) {
	glViewport(0, 0, width, hieght);
}

void Window::Destroy() {
	glfwDestroyWindow(window);
}