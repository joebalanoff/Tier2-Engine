#include "window.h"
#include "../platform/windows_window.h"

namespace Tier2 {
	Scope<Window> Window::Create(const WindowProps& props) {
		return CreateScope<WindowsWindow>(props);
	}
}