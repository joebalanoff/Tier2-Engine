#include "editor_layer.h"

#include "imgui.h"

namespace Tier2 {
	EditorLayer::EditorLayer() : Layer("EditorLayer") { 
		m_sceneHierarchyPanel = new SceneHierarchyPanel();
	}

	void EditorLayer::OnRender() { 
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		ImGuiIO& io = ImGui::GetIO();
		ImGuiStyle& style = ImGui::GetStyle();
		float minWinSizeX = style.WindowMinSize.x;
		style.WindowMinSize.x = 370.0f;
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}
		style.WindowMinSize.x = minWinSizeX;

		if (ImGui::BeginMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				if (ImGui::MenuItem("Open Project...", "Ctrl+O"))
					OpenProject();
			}
		}

		m_sceneHierarchyPanel->OnRender();
	}

	void EditorLayer::OpenProject() {

	}
}
