#pragma once

#include <BehaviorBa.h>

class Ba5001 : public BehaviorBa
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

    Ba5001()
    {
        ((void(__thiscall *)(Ba5001 *))(shared::base + 0x6B0DE0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B3C);
};

VALIDATE_SIZE(Ba5001, 0xB60);