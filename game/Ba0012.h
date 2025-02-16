#pragma once

#include <BehaviorBa.h>

class Ba0012 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
    int field_B40;
    EntityHandle field_B44;
    EntityHandle field_B48;
    EntityHandle field_B4C;
    EntityHandle field_B50;
    EntityHandle field_B54;
    EntityHandle field_B58;
    int field_B5C;
    cEspControler field_B60;

    Ba0012()
    {
        ((void(__thiscall *)(Ba0012 *))(shared::base + 0x6AFF30))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B04);
};

VALIDATE_SIZE(Ba0012, 0xC10);