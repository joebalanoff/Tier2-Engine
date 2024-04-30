#pragma once

#include "../core/layer.h"
#include "panels/scene_hierarchy_panel.h"

namespace Tier2 {
	class EditorLayer : public Layer {
	public:
		EditorLayer();
		~EditorLayer() = default;

		virtual void OnRender() override;
	private:
		void OpenProject();

		SceneHierarchyPanel* m_sceneHierarchyPanel;
	};
}