#pragma once

#include <BehaviorBa.h>

class Ba5002 : public BehaviorBa
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
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;

    Ba5002()
    {
        ((void(__thiscall *)(Ba5002 *))(shared::base + 0x6B0E30))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B40);
};

VALIDATE_SIZE(Ba5002, 0xB80);