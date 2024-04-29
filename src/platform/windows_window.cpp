#include "windows_window.h"
#include <iostream>

namespace Tier2 {
	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description) {
		std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		if (s_GLFWWindowCount == 0) {
			int s = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
		m_window = glfwCreateWindow((int)props.width, (int)props.height, m_data.title.c_str(), nullptr, nullptr);
		++s_GLFWWindowCount;

		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			// Send change size event
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			// Send close event
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			// Send key events
		});

		// Handle rest of callbacks
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0) {
			glfwTerminate();
		}
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		glfwSwapInterval(enabled ? 1 : 0);
		m_data.vSync = enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_data.vSync;
	}
}