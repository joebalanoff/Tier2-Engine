#pragma once

#include <string>
#include "base.h"

namespace Tier2 {
	struct WindowProps {
		std::string title;
		uint32_t width;
		uint32_t height;

		WindowProps(const std::string& _title = "Tier2",
					uint32_t _width = 1600,
					uint32_t _height = 900
					) : title(_title), width(_width), height(_height) {}
	};

	class Window {
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}