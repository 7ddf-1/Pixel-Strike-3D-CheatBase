#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <libloaderapi.h>
#include "../kiero/minhook/include/MinHook.h"
#include <list>
#include "../imgui/imgui_internal.h"




#define _x12_b4 (((__TIME__[7] - '0')) + ((__TIME__[6] - '0') * 10) + \
              ((__TIME__[4] - '0') * 60) + ((__TIME__[3] - '0') * 600) + \
              ((__TIME__[1] - '0') * 3600) + ((__TIME__[0] - '0') * 36000))
#define _r3t_n8f(a1, a2) (a1 + (_x12_b4 % (a2 - a1 + 1)))
template <size_t a1, char a2>
class _q7tX {
public:
    constexpr _q7tX(const char* a3) {
        for (int i = 0; i < a1; i++) {
            _d8r[i] = a3[i] ^ (a2 + i);
        }
    }

    constexpr const char* _g5t() const {
        return &_d8r[0];
    }

    char _d8r[a1]{};
};

template <size_t a1, char a2>
class _f9zY {
public:
    _f9zY(const _q7tX<a1, a2>& a3) {
        for (int i = 0; i < a1; i++) {
            _m4q[i] = a3._g5t()[i];
        }
    }

    ~_f9zY() {
        for (int i = 0; i < a1; i++) {
            _m4q[i] = 0;
        }
    }

    operator char* () {
        if (!_v2p) {
            for (int i = 0; i < a1; i++) {
                _m4q[i] = _m4q[i] ^ (a2 + i);
            }
            _v2p = true;
        }
        return _m4q;
    }

    bool _v2p = false;
    char _m4q[a1]{};
};
inline long _s3tD(const char* a1, int a2) {
    if (strcmp(a1, "true") == 0) {
        return 1;
    }
    return strtol(a1, NULL, a2);
}
inline uintptr_t _p8rT(const char* a1) {
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long) ||
        sizeof(uintptr_t) == sizeof(unsigned long long),
        "1pointer");

    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(a1, nullptr, 16);
    }
    return strtoull(a1, nullptr, 16);
}
#define _k2sF(a1, a2) (char*)[]() -> _f9zY<sizeof(a1)/sizeof(a1[0]), a2>& { \
        constexpr auto _l4n = sizeof(a1)/sizeof(a1[0]); \
        constexpr auto _d5t = _q7tX<_l4n, a2>(a1); \
        thread_local auto _t8f = _f9zY<_l4n, a2>(_d5t); \
        return _t8f; \
    }()
#define _e9cR(a1) (_k2sF(a1, (char)_r3t_n8f(1, 255)))
#define _i7nB(a1, a2) ((int)_s3tD(_e9cR(#a1), a2))
#define _l9gB(a1, a2) (_s3tD(_e9cR(#a1), a2))
#define _i3nT(a1) _i7nB(a1, 10)
#define _l5nG(a1) _l9gB(a1, 10)
#define _p6tR(a1) (_p8rT(_e9cR(#a1)))
#if defined(__linux__) || defined(__ANDROID__)
#include <dlfcn.h>
#define _c4lL(a1, a2) ((a2)(dlsym(RTLD_DEFAULT, _e9cR(a1))))
#elif _WIN32
#endif
#include "IL2CPP_Resolver-main/Unity/Structures/Engine.hpp"
#define _g7oF(a1) get_offset(string2Offset(_e9cR(a1)))
#define _g5tM(a1, a2) IL2CPP::Class::Utils::GetMethodPointer(_e9cR(a1), _e9cR(a2))
#define _g2tA(a1, a2, a3) IL2CPP::Class::Utils::GetMethodPointer(_e9cR(a1), _e9cR(a2), _i3nT(a3))
std::list<void*>QoLz; struct Qkkz { static inline bool x; char* n8; MH_STATUS c; }; Qkkz ___z, * ___y = &___z; void* (*_0O)(void*);
#define _1OZsU static inline
_1OZsU MH_STATUS _02O(MH_STATUS vt, MH_STATUS(*fn)(void*, void*, void**), void* p1, void* p2, void** p3) { return(*fn)(p1, p2, p3); }
_1OZsU MH_STATUS _03O(MH_STATUS vt, MH_STATUS(*fn)(void*), void* p1) { return(*fn)(p1); }
_1OZsU void _05O(std::list<void*>* v, void* t) { v->push_back(t); }
_1OZsU bool _01Z(void* Q, void* W, void** E) {
    ___z.c = _02O(___z.c, MH_CreateHook, Q, W, E); if (((char)___z.c) ^ (MH_OK)) { return(0); }___z.c =
        _03O(___z.c, MH_EnableHook, Q); if (((char)___z.c) ^ (MH_OK)) { return(0); }_05O(&QoLz, Q); return(~(~1));
}
#define _Z(c,n,f)((_01Z)((void*)(IL2CPP::Class::Utils::GetMethodPointer)(_e9cR(c),_e9cR(n)),(void*)(f),(void**)(&flexorg_##f)))
Unity::Vector2 ScreenSize = { 0, 0 };
Unity::Vector2 ScreenCenter = { 0, 0 };
bool WorldToScreen(Unity::Vector3 world, Unity::Vector2& screen)
{
    Unity::CCamera* CameraMain = Unity::Camera::GetMain();
    if (!CameraMain) {
        return false;
    }

    Unity::Vector3 buffer = CameraMain->CallMethodSafe<Unity::Vector3>("WorldToScreenPoint", world, Unity::eye::mono);

    if (buffer.x > ScreenSize.x || buffer.y > ScreenSize.y || buffer.x < 0 || buffer.y < 0 || buffer.z < 0)
    {
        return false;
    }

    if (buffer.z > 0.0f)
    {
        screen = Unity::Vector2(buffer.x, ScreenSize.y - buffer.y);
    }

    if (screen.x > 0 || screen.y > 0)
    {
        return true;
    }
}


