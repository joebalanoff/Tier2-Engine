#pragma once

#include <vector>

#include "layer.h"

namespace Tier2 {
	class LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		std::vector<Layer*> m_layers;
	private:
		unsigned int m_layerInsertIndex = 0;
	};
}