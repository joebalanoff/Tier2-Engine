#include "window.h"

namespace Tier2 {
	Window::Window() : m_window(nullptr) {
		glfwSetErrorCallback(GLFW_ERROR_CALLBACK);
		if (!glfwInit()) {
			return;
		}

		const char* glsl_version = "#version 130";
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

		m_window = glfwCreateWindow(1280, 700, "Tier2", nullptr, nullptr);
		if (m_window == nullptr) {
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);
		glfwSwapInterval(1);
	}

	Scope<Window> Window::CreateWindow(){
		return CreateScope<Window>();
	}
}