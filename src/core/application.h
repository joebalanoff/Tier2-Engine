#pragma once

#include <string>
#include <functional>

#include "layer.h"
#include "layer_stack.h"

#include "window.h"

#include "../gui/imgui/im_gui_layer.h"

#include "base.h"

namespace Tier2 {
	struct ApplicationCommandLineArgs {
		int count = 0;
		char** args = nullptr;

		const char* operator[](int index) const {
			return args[index];
		}
	};

	struct ApplicationSpecification {
		std::string name = "Tier2";
		std::string workingDirectory;
		ApplicationCommandLineArgs commandLineArgs;
	};

	class Application {
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_window; }

		void Run();
		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_imGuiLayer; }

		static Application& Get() { return *s_instance; }

		const ApplicationSpecification& GetSpecification() const { return m_specification; }
	private:
		bool OnWindowClose();
		bool OnWindowResize();

		ApplicationSpecification m_specification;
		Scope<Window> m_window;
		ImGuiLayer* m_imGuiLayer;
		bool m_running = true;
		bool m_minimized = false;

		LayerStack m_layerStack;
	private:
		static Application* s_instance;
	};
}