#include "application.h"

#include <cstdio>

namespace Tier2 {
	Application* Application::s_instance = nullptr;

	Application::Application() : m_window(nullptr), m_imGuiLayer(nullptr), m_editorLayer(nullptr) { }

	Application::~Application() {}

	void Application::Init() {
		m_window = Window::CreateWindow();

		m_layerStack = LayerStack();

		m_imGuiLayer = new ImGuiLayer();
		m_layerStack.PushLayer(m_imGuiLayer);

		m_editorLayer = new EditorLayer();
		m_layerStack.PushLayer(m_editorLayer);

		GLFWwindow* window = static_cast<GLFWwindow*>(m_window->GetNativeWindow());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");
	}

	void Application::Run() {
		GLFWwindow* window = static_cast<GLFWwindow*>(m_window->GetNativeWindow());
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();

			m_imGuiLayer->Begin();
			
			{
				for (Layer* layer : m_layerStack.m_layers) {
					layer->OnUpdate();
				}

				for (Layer* layer : m_layerStack.m_layers) {
					layer->OnRender();
				}
			}
			
			m_imGuiLayer->End();

			glfwSwapBuffers(window);
		}
	}
}