#pragma once

#include <BehaviorAppBase.h>

class KamaitatiObj : public BehaviorAppBase
{
public:
    cEspControler field_A00;
    int field_AB0;
    int field_AB4;
    int field_AB8;
    int field_ABC;
    int field_AC0;
    int field_AC4;
    int field_AC8;
    int field_ACC;
    int field_AD0;
    int field_AD4;
    int field_AD8;
    int field_ADC;
    int field_AE0;
    int field_AE4;
    int field_AE8;
    int field_AEC;
    int field_AF0;
    int field_AF4;
    int field_AF8;
    int field_AFC;
    int field_B00;
    int field_B04;
    int field_B08;
    int field_B0C;
    int field_B10;
    int field_B14;
    int field_B18;
    int field_B1C;

    KamaitatiObj()
    {
        ((void(__thiscall *)(KamaitatiObj*))(shared::base + 0x6B1B60))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735B24);
};

VALIDATE_SIZE(KamaitatiObj, 0xB20);