#pragma once

#include <BehaviorAppBase.h>

class ExcelPartsObj : public BehaviorAppBase
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
    EntityHandle field_AFC;
    int field_B00;
    int field_B04;
    int field_B08;
    int field_B0C;
    int field_B10;
    int field_B14;
    int field_B18;
    int field_B1C;

    ExcelPartsObj()
    {
        ((void(__thiscall *)(ExcelPartsObj*))(shared::base + 0x6AEB10))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17351D0);
};

class ExcelObj : public BehaviorAppBase
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
    EntityHandle field_AD0[5];
    int field_AE4;
    int field_AE8;
    int field_AEC;
    int field_AF0;
    int field_AF4;
    EntityHandle field_AF8;
    int field_AFC;
    int field_B00;
    int field_B04;
    int field_B08;
    int field_B0C;
    int field_B10;
    int field_B14;
    int field_B18;
    int field_B1C;

    ExcelObj()
    {
        ((void(__thiscall *)(ExcelObj *))(shared::base + 0x6AEA30))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17351CC);
};

VALIDATE_SIZE(ExcelObj, 0xB20);
VALIDATE_SIZE(ExcelPartsObj, 0xB20);