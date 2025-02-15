#pragma once

#include <BehaviorBm.h>

class Bm020e : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm020e()
    {
        ((void(__thiscall *)(Bm020e *))(shared::base + 0x6B0A20))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B9C);
};

VALIDATE_SIZE(Bm020e, 0xB50);