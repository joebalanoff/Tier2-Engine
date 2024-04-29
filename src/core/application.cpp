#include "application.h"

#include <filesystem>
#include <iostream>

#include "window.h"

namespace Tier2 {
	Application* Application::s_instance = nullptr;

	Application::Application(const ApplicationSpecification& specification) : m_specification(specification) {
		s_instance = this;

		if (!m_specification.workingDirectory.empty()) {
			//std::filesystem::current_path(m_specification.workingDirectory);
		}

		m_window = Window::Create(WindowProps(m_specification.name));
		
		m_imGuiLayer = new ImGuiLayer();
		PushOverlay(m_imGuiLayer);
	}

	Application::~Application() {

	}

	void Application::PushLayer(Layer* layer) {
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Close() {
		m_running = false;
	}

	void Application::Run() {
		while (m_running) {
			if (!m_minimized) {
				{
					for (Layer* layer : m_layerStack) {
						layer->OnUpdate(0); // timestep
					}
				}

				m_imGuiLayer->Begin();
				{
					for (Layer* layer : m_layerStack) {
						layer->OnImGuiRender();
					}
				}
				m_imGuiLayer->End();
			}
			m_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose() {
		m_running = false;
		return true;
	}

	bool Application::OnWindowResize() {
		return false;
	}
}