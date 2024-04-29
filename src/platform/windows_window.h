#pragma once

#include <GLFW/glfw3.h>
#include "../core/window.h"

namespace Tier2 {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_data.width; }
		unsigned int GetHeight() const override { return m_data.height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_window;
		
		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;
		};

		WindowData m_data;
	};
}