#pragma once

#include <BehaviorBm.h>

class Bm6012 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    cEspControler field_B50;

    Bm6012()
    {
        ((void(__thiscall *)(Bm6012 *))(shared::base + 0x6B1790))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354EC);
};

VALIDATE_SIZE(Bm6012, 0xC00);