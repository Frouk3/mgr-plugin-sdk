#pragma once

#include <BehaviorBa.h>

class Ba0160 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba0160()
    {
        ((void(__thiscall *)(Ba0160 *))(shared::base + 0x6B0550))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B24);
};

VALIDATE_SIZE(Ba0160, 0xB40);