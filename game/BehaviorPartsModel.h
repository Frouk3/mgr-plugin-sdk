#pragma once

#include <BehaviorAppBase.h>

class BehaviorPartsModel : public BehaviorAppBase
{
public:
    EntityHandle field_A00;
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
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    int field_A40;
    int field_A44;
    int field_A48;
    int field_A4C;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;

    BehaviorPartsModel()
    {
        ((void(__thiscall *)(BehaviorPartsModel*))(shared::base + 0x6AE2C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C8C);
};

VALIDATE_SIZE(BehaviorPartsModel, 0xA60);