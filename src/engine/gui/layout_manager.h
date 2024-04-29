#pragma once

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_internal.h>

#include "gui_manager.h"

class LayoutManager {
public:
	LayoutManager(GLFWwindow* window);
	~LayoutManager();

	void render();
private:
	GLFWwindow* m_window;
};