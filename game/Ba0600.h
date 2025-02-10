#pragma once

#include <BehaviorBa.h>

class Ba0600 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;

    Ba0600()
    {
        ((void(__thiscall *)(Ba0600 *))(shared::base + 0x6B0460))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B34);
};

VALIDATE_SIZE(Ba0600, 0xB60);