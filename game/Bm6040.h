#pragma once

#include <BehaviorBm.h>

class Bm6040 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;

    Bm6040()
    {
        ((void(__thiscall *)(Bm6040 *))(shared::base + 0x6B17F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354F0);
};

VALIDATE_SIZE(Bm6040, 0xB70);