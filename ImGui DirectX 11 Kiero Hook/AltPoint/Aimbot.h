#pragma once
std::vector<Unity::CGameObject*> healthObjects;
float Vector2distance(const Unity::Vector2& a, const Unity::Vector2& b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
Unity::Vector2 getclosestone() {
    float closest = 9999999.f;
    Unity::Vector2 result = ScreenCenter;
    bool found = false;
    for (size_t i = 0; i < healthObjects.size(); ++i) {
        if (!healthObjects[i])
            continue;

        auto t = healthObjects[i]->GetTransform();
        if (!t)
            continue;
        Unity::Vector3 pos = t->GetPosition();
        pos.y += 2.8f;
        Unity::Vector2 screen_pos;
        if (!WorldToScreen(pos, screen_pos))
            continue;
        float dist = Vector2distance(screen_pos, ScreenCenter);
        if (dist > (ScreenSize.y / 2) * (fov / 90.0f))
            continue;
        if (dist < closest) {
            closest = dist;
            result = screen_pos;
            found = true;
        }
    }

    return found ? result : ScreenCenter;
}
void MovMD(Unity::Vector2 targetPos) {
    float delX = (targetPos.x - ScreenCenter.x) / Smoothness;
    float delY = (targetPos.y - ScreenCenter.y) / Smoothness;
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dx = static_cast<LONG>(delX);
    input.mi.dy = static_cast<LONG>(delY);
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, &input, sizeof(INPUT));
}
void Raim() {
    if (!aimbot)
        return;
    if (GetAsyncKeyState(aimKey) & 0x8000) {
        aimact = true;
        Unity::Vector2 aimtarget = getclosestone();
        MovMD(aimtarget);
    }
    else {
        aimact = false;
    }
    if (showFov) {
        ImDrawList* drawL = ImGui::GetBackgroundDrawList();
        float fovR = (ScreenSize.y / 2) * (fov / 90.0f);
        drawL->AddCircle(
            ImVec2(ScreenCenter.x, ScreenCenter.y),
            fovR,
            IM_COL32(255, 255, 255, 255),
            48,
            2.0f
        );
        drawL->AddCircle(
            ImVec2(ScreenCenter.x, ScreenCenter.y),
            fovR,
            IM_COL32(255, 255, 0, 100),
            48,
            1.0f
        );
    }
}
void LoopAimbot() {
     Raim();
}