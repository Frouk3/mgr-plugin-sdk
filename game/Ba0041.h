#pragma once

#include <BehaviorAppBase.h>

class Ba0041 : public BehaviorAppBase
{
public:
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    int field_A2C;

    Ba0041()
    {
        ((void(__thiscall *)(Ba0041 *))(shared::base + 0x6B0CA0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D7C);
};

VALIDATE_SIZE(Ba0041, 0xA30);