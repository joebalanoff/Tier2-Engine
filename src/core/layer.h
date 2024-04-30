#pragma once

#include <string>

namespace Tier2 {
	class Layer {
	public:
		Layer(const std::string& debugName);

		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
	private:
		const std::string& m_debugName;
	};
}