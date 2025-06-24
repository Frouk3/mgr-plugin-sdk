#pragma once

#include <BehaviorBm.h>

class Bm0600 : public BehaviorBm
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

    Bm0600()
    {
        ((void(__thiscall *)(Bm0600 *))(shared::base + 0x6B0410))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BE4);
};

VALIDATE_SIZE(Bm0600, 0xB60);