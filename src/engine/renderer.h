#pragma once

#include <iostream>

#include "gui/gui_manager.h"
#include "gui/layout_manager.h"

class Renderer {
public:
	Renderer();
	~Renderer();

	bool init();

	void render();

	void shutdown();

	GLFWwindow* getWindow() const;
private:
	GLFWwindow* m_window;
	std::unique_ptr<GuiManager> m_guiManager;
};