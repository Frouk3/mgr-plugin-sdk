#pragma once

#include <BehaviorBa.h>

class Ba0066 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba0066()
    {
        ((void(__thiscall *)(Ba0066*))(shared::base + 0x6B0200))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B1C);
};

VALIDATE_SIZE(Ba0066, 0xB40);