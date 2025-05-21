#include "AltPoint/Aimbot.h"
void MainEsp2D() {
    MountainHarvest(&healthObjects, "Health");
    ImDrawList* drawL = ImGui::GetBackgroundDrawList();
    ScreenSize = Unity::Vector2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y);
    ScreenCenter = Unity::Vector2(ScreenSize.x / 2, ScreenSize.y / 2);

    for (size_t i = 0; i < healthObjects.size(); i++) {
        auto obj = healthObjects[i]; if (!obj) continue;
        auto transform = obj->GetTransform(); if (!transform) continue;
        Unity::Vector3 worldPos = transform->GetPosition();
        Unity::Vector3 headPos = worldPos; headPos.y += 3.1f;
        Unity::Vector3 feetPos = worldPos; feetPos.y -= 0.f;
        Unity::Vector2 headScreen, feetScreen;
        if (!WorldToScreen(headPos, headScreen) || !WorldToScreen(feetPos, feetScreen))
            continue;
        float height = feetScreen.y - headScreen.y;
        float width = height * 0.5f;
        float l = headScreen.x - width / 2;
        float t = headScreen.y;
        float r = headScreen.x + width / 2;
        float b = feetScreen.y;
        ImU32 boxCol = IM_COL32(255, 255, 255, 255);
        if (aimact) {
            Unity::Vector2 aimtarget = getclosestone();
            if (Vector2distance(headScreen, aimtarget) < 5.0f) {
                boxCol = IM_COL32(255, 0, 0, 255);
            }
        }
        ImU32 outlineCol = IM_COL32(0, 0, 0, 255);
        drawL->AddRect(ImVec2(l - 1, t - 1), ImVec2(r + 1, b + 1), outlineCol, 0.0f, 0, 1.0f);
        drawL->AddRect(ImVec2(l + 1, t + 1), ImVec2(r - 1, b - 1), outlineCol, 0.0f, 0, 1.0f);
        drawL->AddRect(ImVec2(l, t), ImVec2(r, b), boxCol, 0.0f, 0, 1.0f);
    }
}
void LoopESP() {
    ScreenSize = Unity::Vector2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y);
    ScreenCenter = Unity::Vector2(ScreenSize.x / 2, ScreenSize.y / 2);

    if (esp2d)
    {
        MainEsp2D();
    }
}