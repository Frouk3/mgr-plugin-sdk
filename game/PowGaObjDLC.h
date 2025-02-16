#pragma once

#include <BehaviorAppBase.h>

class PowGaObjDLC : public BehaviorAppBase
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
    EntityHandle field_AD0;
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

    PowGaObjDLC()
    {
        ((void(__thiscall *)(PowGaObjDLC *))(shared::base + 0x6B3E50))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735ABC);
};

VALIDATE_SIZE(PowGaObjDLC, 0xB00);