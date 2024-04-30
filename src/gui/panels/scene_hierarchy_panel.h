#pragma once

#include "../../core/layer.h"

namespace Tier2 {
	class SceneHierarchyPanel : public Layer {
	public:
		SceneHierarchyPanel();
		~SceneHierarchyPanel() = default;

		virtual void OnRender() override;
	};
}