#pragma once

#include <BehaviorBm.h>

class Bm0238 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    cEspControler field_B50;
    int field_C00;
    int field_C04;
    int field_C08;
    int field_C0C;

    Bm0238()
    {
        ((void(__thiscall *)(Bm0238 *))(shared::base + 0x6B02C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BA8);
};

VALIDATE_SIZE(Bm0238, 0xC10);