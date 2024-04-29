#include "layout_manager.h"
#include <iostream>


LayoutManager::LayoutManager(GLFWwindow* window) : m_window(window) {}

LayoutManager::~LayoutManager() {}

void LayoutManager::render() {
    ImGui::SetNextWindowPos(ImVec2(0, 0));                                                  // always at the window origin
    ImGui::SetNextWindowSize(ImVec2(float(800), float(600)));    // always at the window size

    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoBringToFrontOnFocus |                 // we just want to use this window as a host for the menubar and docking
        ImGuiWindowFlags_NoNavFocus |                                                      // so turn off everything that would make it act like a window
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_MenuBar |
        ImGuiWindowFlags_NoBackground;                                                      // we want our game content to show through this window, so turn off the background.

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));                          // we don't want any padding for windows docked to this window frame

    bool show = (ImGui::Begin("Main", NULL, windowFlags));                                   // show the "window"
    ImGui::PopStyleVar();                                                                    // restore the style so inner windows have fames

    // create a docking space inside our inner window that lets prevents anything from docking in the central node (so we can see our game content)
    ImGui::DockSpace(ImGui::GetID("Dockspace"), ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);
    if (show)
    {
        // Do a menu bar with an exit menu
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Exit"))
                    //quit = true;

                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    }
    ImGui::End();
}