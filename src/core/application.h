#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>

#include "base.h"

#include "window.h"

#include "layer_stack.h"

#include "../gui/im_gui_layer.h"
#include "../gui/editor_layer.h"

namespace Tier2 {
	class Application {
	public:
		Application();
		~Application();

		Window& GetWindow() { return *m_window; }

		void Init();
		void Run();

		static Application& Get() { return *s_instance; }
	private:
		Scope<Window> m_window;

		LayerStack m_layerStack;

		ImGuiLayer* m_imGuiLayer;
		EditorLayer* m_editorLayer;

		static Application* s_instance;
	};
}