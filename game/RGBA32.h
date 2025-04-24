#pragma once
#include "shared.h"

struct RGBA32
{
    float r;
    float g;
    float b;
    float a;

    RGBA32()
    {
        r = 0.f;
        g = 0.f;
        b = 0.f;
        a = 1.f;
    }

    RGBA32(float r, float g, float b, float a = 1.f) : r(r), g(g), b(b), a(a) {};
};

VALIDATE_SIZE(RGBA32, 0x10);