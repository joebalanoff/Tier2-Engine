#pragma once

#include <string>

namespace Tier2 {
	class Layer {
	public:
		Layer(const std::string& name = "New Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent() {} // Events?

		const std::string& GetName() const { return m_debugName; }
	protected:
		std::string m_debugName;
	};
}