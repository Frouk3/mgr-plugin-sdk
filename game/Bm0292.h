#pragma once

#include <BehaviorBm.h>

class Bm0292 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm0292()
    {
        ((void(__thiscall *)(Bm0292 *))(shared::base + 0x6B0C00))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BB4);
};

VALIDATE_SIZE(Bm0292, 0xB50);