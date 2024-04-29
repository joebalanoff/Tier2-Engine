#pragma once

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_internal.h>

namespace Tier2 {
	class LayoutManager {
	public:
		LayoutManager(GLFWwindow* window);
		~LayoutManager() = default;

		void render();
	private:
		GLFWwindow* m_window;
	};
}