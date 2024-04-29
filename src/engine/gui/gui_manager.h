#pragma once

#include "layout_manager.h"

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class GuiManager {
public:
	GuiManager(GLFWwindow* window);
	~GuiManager();

	void init();
	void beginFrame();
	void endFrame();
	void shutdown();

	LayoutManager* getLayoutManager() const;
private:
	GLFWwindow* m_window;
	LayoutManager* m_layoutManager;

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

