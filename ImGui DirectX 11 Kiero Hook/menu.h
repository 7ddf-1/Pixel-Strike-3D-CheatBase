#pragma once
#include "includes.h"
//  100% not skidded
void DrawUI()
{
    auto _sw_size = 600, _sw_sizeh = 400;
    auto _sw_sbw = 140.0f;

    auto _sw_gc = ImVec4(0.3f, 0.7f, 1.0f, 0.8f);
    auto _sw_atc = ImVec4(0.15f, 0.35f, 0.6f, 1.0f);
    auto _sw_itc = ImVec4(0.1f, 0.2f, 0.3f, 0.9f);
    auto _sw_tc = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    auto _sw_ttc = ImVec4(0.9f, 0.7f, 1.0f, 1.0f);
    auto _sw_dc = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);

    auto _sw_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize;

    static int _sw_tab = 0;

    ImGui::SetNextWindowSize(ImVec2(_sw_size, _sw_sizeh), ImGuiCond_Always);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);

    if (ImGui::Begin("##mainthing", nullptr, _sw_flags))
    {
        auto _sw_sb = ImVec4(0.05f, 0.05f, 0.08f, 0.94f);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, _sw_sb);
        ImGui::BeginChild("##sidebar", ImVec2(_sw_sbw, _sw_sizeh), false);

        ImGui::PushStyleColor(ImGuiCol_Text, _sw_ttc);
        ImGui::SetCursorPosY(15);
        auto _sw_t1 = "Pixel Strike";
        auto _sw_t2 = "Base By 0SD47";
        auto _sw_t1w = ImGui::CalcTextSize(_sw_t1).x;
        auto _sw_t2w = ImGui::CalcTextSize(_sw_t2).x;
        ImGui::SetCursorPosX((_sw_sbw - _sw_t1w) / 2);
        ImGui::Text(_sw_t1);
        ImGui::SetCursorPosX((_sw_sbw - _sw_t2w) / 2);
        ImGui::Text(_sw_t2);
        ImGui::PopStyleColor();

        auto _sw_hovv = ImVec4(0.2f, 0.4f, 0.7f, 1.0f);
        auto _sw_actv = ImVec4(0.3f, 0.5f, 0.8f, 1.0f);

        auto _sw_dt = [&](const char* _l, int _id, float _y) {
            ImGui::SetCursorPosY(_y);
            auto _clr = _id == _sw_tab ? _sw_atc : _sw_itc;
            ImGui::PushStyleColor(ImGuiCol_Button, _clr);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, _sw_hovv);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, _sw_actv);
            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 10));
            auto _r = ImGui::Button(_l, ImVec2(_sw_sbw, 40));
            if (_r) _sw_tab = _id;
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(3);
            };

        _sw_dt("GamePlay", 0, 60);
        _sw_dt("Movement", 1, 110);

        ImGui::EndChild();
        ImGui::PopStyleColor();

        ImGui::SameLine();

        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 8.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(20, 20));
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.07f, 0.07f, 0.12f, 0.94f));

        auto _sw_cw = _sw_size - _sw_sbw;
        ImGui::BeginChild("##contentarea", ImVec2(_sw_cw, _sw_sizeh), false);

        ImGui::PushStyleColor(ImGuiCol_Text, _sw_tc);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.1f, 0.15f, 0.2f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_CheckMark, _sw_gc);
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, _sw_gc);
        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.4f, 0.8f, 1.0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.15f, 0.25f, 0.5f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.25f, 0.35f, 0.6f, 0.9f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.4f, 0.7f, 1.0f));

        if (_sw_tab == 0)
        {
            ImGui::Text("GamePlay Features");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("No Recoil", &norecoil);

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Mass Loop Reload", &MassLoopReload);

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Rapid Fire", &RapidFire);

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Set Weapon", &SetWeapon);

            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();

            auto _sw_gr = ImGui::Button("Get Reward", ImVec2(140, 35));
            GetReward = _sw_gr ? true : false;
        }
        else if (_sw_tab == 1)
        {
            ImGui::Text("Movement Features");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Speed Test", &SpeedTest);
            ImGui::SameLine();
            ImGui::TextColored(_sw_dc, "[Bannable]");

            ImGui::Spacing();
            ImGui::Spacing();

            if (SpeedTest)
            {
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.12f, 0.18f, 0.25f, 0.8f));
                ImGui::SliderFloat("Speed Multiplier", &SpeedTestSlider, 0.0f, 120.0f, "%.1f");
                ImGui::PopStyleColor();
            }

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Jump Boost", &JumpBoost);

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Fly", &Fly);

            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Checkbox("Infinite Jump", &InfiniteJump);
        }

        ImGui::PopStyleColor(8);
        ImGui::EndChild();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar(2);
    }

    ImGui::PopStyleVar(4);
    ImGui::End();
}
