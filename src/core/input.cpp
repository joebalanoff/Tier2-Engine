#include "input.h"

Input::Input(GLFWwindow* window) : m_window(window) {}

void Input::processInput() {
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_window, true);
	}
}