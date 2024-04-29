#include "layout_manager.h"
#include <iostream>

LayoutManager::LayoutManager(GLFWwindow* window) : m_window(window) {}

void LayoutManager::render() {
	// TODO: Implement docking with something like this:
	// https://github.com/TheCherno/Hazel/blob/master/Hazelnut/src/EditorLayer.cpp
	ImGui::ShowDemoWindow();
}