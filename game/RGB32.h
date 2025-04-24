#pragma once
#include <shared.h>

struct RGB32
{
    float r;
    float g;
    float b;

    RGB32()
    {
        r = 0.f;
        g = 0.f;
        b = 0.f;
    }

    RGB32(float r, float g, float b) : r(r), g(g), b(b) {};
};

VALIDATE_SIZE(RGB32, 0xC);