#include "scene_hierarchy_panel.h"

#include "imgui.h"

namespace Tier2 {
	SceneHierarchyPanel::SceneHierarchyPanel() : Layer("") { }

	void SceneHierarchyPanel::OnRender() {
		ImGui::Begin("Scene Hierarchy");



		ImGui::End();
	}
}