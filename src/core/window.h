#pragma once

#include <cstdio>
#include <GLFW/glfw3.h>

#include "base.h"

static void GLFW_ERROR_CALLBACK(int error, const char* description) {
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

namespace Tier2 {
	class Window {
	public:
		Window();
		~Window() = default;

		uint32_t GetWidth() const;
		uint32_t GetHeight() const;

		void* GetNativeWindow() const { return m_window; }

		static Scope<Window> CreateWindow();
	private:
		GLFWwindow* m_window;
	};
}