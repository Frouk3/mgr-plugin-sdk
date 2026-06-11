#pragma once

#include "BehaviorBgBase.h"

class BehaviorBa : public BehaviorBgBase
{
public:
    cEspControler field_A70;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;

    BehaviorBa()
    {
        MAKE_CALL(shared::base + 0x6C3E80, void(__thiscall *)(BehaviorBa *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C58);
};

VALIDATE_SIZE(BehaviorBa, 0xB30);