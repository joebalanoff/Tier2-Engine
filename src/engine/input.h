#pragma once

#include <GLFW/glfw3.h>

class Input {
public:
	Input(GLFWwindow* window);

	void processInput();

private:
	GLFWwindow* m_window;
};