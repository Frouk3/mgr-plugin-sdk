#pragma once

#include <BehaviorBm.h>

class Bm6000 : public BehaviorBm
{
public:
    float field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm6000()
    {
        ((void(__thiscall *)(Bm6000 *))(shared::base + 0x6B14F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354E8);
};

VALIDATE_SIZE(Bm6000, 0xB50);