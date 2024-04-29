#include "renderer.h"

Renderer::Renderer() : m_window(nullptr), m_guiManager(nullptr) {}

Renderer::~Renderer() {
	glfwTerminate();
}

bool Renderer::init() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	m_window = glfwCreateWindow(800, 600, "Game Engine Editor", nullptr, nullptr);
	if (!m_window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	m_guiManager = std::make_unique<GuiManager>(m_window);
	m_guiManager->init();

	return true;
}

void Renderer::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_guiManager->beginFrame();

	m_guiManager->getLayoutManager()->render();

	m_guiManager->endFrame();
}

void Renderer::shutdown() {
	if (m_guiManager) {
		m_guiManager->shutdown();
		m_guiManager.reset();
	}
	if (m_window) {
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
	glfwTerminate();
}

GLFWwindow* Renderer::getWindow() const {
	return m_window;
}