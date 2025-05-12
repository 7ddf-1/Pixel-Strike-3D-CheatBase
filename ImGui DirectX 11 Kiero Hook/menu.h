#pragma once
#include "includes.h"

void Drawui()
{
    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Always);
    ImGuiWindowFlags winflags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize;
    if (ImGui::Begin("##mainthing", nullptr, winflags))
    {
        ImGui::Text("Pixel Strike Base By 0SD47");
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::Checkbox("No Recoil", &norecoil);
        ImGui::Spacing();

        ImGui::Checkbox("Mass Loop Reload", &MassLoopReload);
        ImGui::Spacing();

        ImGui::Checkbox("Speed Test", &SpeedTest);
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "[Bannable]");
        ImGui::Spacing();

        ImGui::Checkbox("Jump Boost", &JumpBoost);
        ImGui::Spacing();

        ImGui::Checkbox("Fly", &Fly);
        ImGui::Spacing();

        ImGui::Checkbox("Infinite Jump", &InfiniteJump);
        ImGui::Spacing();

        ImGui::Checkbox("Rapid Fire", &RapidFire);
        ImGui::Spacing();

        ImGui::Checkbox("Set Weapon", &SetWeapon);
        ImGui::Spacing();

        if (SpeedTest)
        {
            ImGui::SliderFloat("Speed Multiplier", &SpeedTestSlider, 0.0f, 120.0f, "%.1f");
        }

        ImGui::Spacing();

        if (ImGui::Button("Get Reward", ImVec2(120, 30)))
        {
            GetReward = true;
        }
        else
        {
            GetReward = false;
        }
    }

    ImGui::End();
}