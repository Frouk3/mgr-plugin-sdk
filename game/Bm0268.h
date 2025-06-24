#pragma once

#include <BehaviorBm.h>

class Bm0268 : public BehaviorBm
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
    cEspControler field_B60;
    cEspControler field_C10;
    int field_CC0;
    int field_CC4;
    int field_CC8;
    int field_CCC;

    Bm0268()
    {
        ((void(__thiscall *)(Bm0268 *))(shared::base + 0x6B08D0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BAC);
};

VALIDATE_SIZE(Bm0268, 0xCD0);