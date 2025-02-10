#pragma once

#include <BehaviorBa.h>

class Ba0105 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba0105()
    {
        ((void(__thiscall *)(Ba0105 *))(shared::base + 0x6B1310))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B20);
};

VALIDATE_SIZE(Ba0105, 0xB40);