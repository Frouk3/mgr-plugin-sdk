#pragma once

#include <BehaviorBm.h>

class Bm0235 : public BehaviorBm
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
    int field_C10;
    int field_C14;
    int field_C18;
    int field_C1C;
    int field_C20;
    int field_C24;
    int field_C28;
    int field_C2C;

    Bm0235()
    {
        ((void(__thiscall *)(Bm0235 *))(shared::base + 0x6B0250))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BA4);
};

VALIDATE_SIZE(Bm0235, 0xC30);