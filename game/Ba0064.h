#pragma once

#include <BehaviorBgBase.h>

class Ba0064 : public BehaviorBgBase
{
public:
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;

    Ba0064()
    {
        ((void(__thiscall *)(Ba0064 *))(shared::base + 0x6A6DC0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B18);
};

VALIDATE_SIZE(Ba0064, 0xAA0);