#pragma once

#include <BehaviorBm.h>

class Bm0429 : public BehaviorBm
{
public:
    cEspControler field_B40;
    int field_BF0;
    int field_BF4;
    int field_BF8;
    int field_BFC;

    Bm0429()
    {
        ((void(__thiscall *)(Bm0429 *))(shared::base + 0x6B0870))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BE0);
};

VALIDATE_SIZE(Bm0429, 0xC00);