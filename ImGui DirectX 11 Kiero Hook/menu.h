#pragma once
#include "includes.h"

void DrawUI()
{
    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Once);
    auto window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize;
    if (ImGui::Begin("Pixel Strike - Base By 0SD47", nullptr, window_flags))
    {
        ImGui::Text("Pixel Strike - Base By 0SD47");
        if (ImGui::BeginTabBar("MainTabBar", ImGuiTabBarFlags_None))
        {
            if (ImGui::BeginTabItem("Aim"))
            {
                ImGui::Text("Aimbot Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("Aimbot", &aimbot);
                ImGui::Spacing();
                ImGui::Checkbox("Draw FOV", &showFov);
                ImGui::Spacing();
                ImGui::SliderFloat("FOV", &fov, 1.0f, 180.0f);
                ImGui::Spacing();
                ImGui::SliderFloat("Smoothness", &Smoothness, 1.0f, 70.0f);
                ImGui::Spacing();
                ImGui::Spacing();
                if (ImGui::Combo("Aim Key", &currentHotkey, HotKeys, IM_ARRAYSIZE(HotKeys))) {
                    aimKey = HotKeyCodes[currentHotkey];
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("GamePlay"))
            {
                ImGui::Text("GamePlay Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("No Recoil", &norecoil);
                ImGui::Spacing();
                ImGui::Checkbox("Mass Loop Reload", &MassLoopReload);
                ImGui::Spacing();
                ImGui::Checkbox("Rapid Fire", &RapidFire);
                ImGui::Spacing();
                ImGui::Checkbox("Set Weapon", &SetWeapon);
                ImGui::Spacing();
                ImGui::Checkbox("ESP 2D", &esp2d);
                ImGui::Spacing();
                ImGui::Spacing();
                if (ImGui::Button("Get Reward", ImVec2(140, 30)))
                {
                    GetReward = true;
                }
                else
                {
                    GetReward = false;
                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Movement"))
            {
                ImGui::Text("Movement Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("Fly", &Fly);
                ImGui::Spacing();
                ImGui::Checkbox("Infinite Jump", &InfiniteJump);
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}
