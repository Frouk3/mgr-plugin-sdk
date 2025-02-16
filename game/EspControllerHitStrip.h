#pragma once

#include <cEspControler.h>

class EspControllerHitStrip : public cEspControler
{
public:
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
    float field_C8;
    float field_CC;

    EspControllerHitStrip()
    {
        ((void (__thiscall *)(EspControllerHitStrip*))(shared::base + 0xAAAAB0))(this);
    }
};

VALIDATE_SIZE(EspControllerHitStrip, 0xD0);