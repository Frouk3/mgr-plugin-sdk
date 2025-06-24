#pragma once

#include <BehaviorBm.h>

class Bm0013 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm0013()
    {
        ((void(__thiscall *)(Bm0013 *))(shared::base + 0x6B05F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B78);
};

VALIDATE_SIZE(Bm0013, 0xB50);