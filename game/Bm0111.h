#pragma once

#include <BehaviorBm.h>

class Bm0111 : public BehaviorBm
{
public:

    Bm0111()
    {
        ((void(__thiscall *)(Bm0111 *))(shared::base + 0x6B01B0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B80);
};

VALIDATE_SIZE(Bm0111, 0xB40);