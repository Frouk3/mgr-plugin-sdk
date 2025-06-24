#pragma once

#include <BehaviorBm.h>

class Bm0403 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm0403()
    {
        ((void(__thiscall *)(Bm0403 *))(shared::base + 0x6B0500))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BD8);
};

VALIDATE_SIZE(Bm0403, 0xB50);