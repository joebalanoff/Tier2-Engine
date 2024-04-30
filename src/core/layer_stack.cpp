#include "layer_stack.h"

namespace Tier2 {
	LayerStack::LayerStack() {}

	LayerStack::~LayerStack() {
		for (Layer* layer : m_layers) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
		layer->OnAttach();
		m_layerInsertIndex++;
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
		if (it != m_layers.begin() + m_layerInsertIndex) {
			layer->OnDetach();
			m_layers.erase(it);
			m_layerInsertIndex--;
		}
	}
}
