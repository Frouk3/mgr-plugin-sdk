#pragma once

#include <BehaviorAppBase.h>

class DlcCatBehavior : public BehaviorAppBase
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

    DlcCatBehavior()
    {
        ((void(__thiscall *)(DlcCatBehavior*))(shared::base + 0x6B19C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354D4);
};

VALIDATE_SIZE(DlcCatBehavior, 0xA30);