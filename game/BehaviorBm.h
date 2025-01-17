#pragma once

#include "BehaviorBgBase.h"

class BehaviorBm : public BehaviorBgBase
{
public:
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    cEspControler field_A80;
    int field_B30;
    int field_B34;
    float field_B38;
    int field_B3C;

    BehaviorBm()
    {
        ((void (__thiscall *)(BehaviorBm *))(shared::base + 0x6C71A0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9C54);
};

VALIDATE_SIZE(BehaviorBm, 0xB40);