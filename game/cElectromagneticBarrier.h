#pragma once

#include <GimmickBehaviorBase.h>

class cElectromagneticBarrier : public GimmickBehaviorBase
{
public:
    int field_B40;
    float field_B44;
    float field_B48;
    float field_B4C;
    float field_B50;
    float field_B54;
    float field_B58;
    float field_B5C;
    float field_B60;
    float field_B64;
    int field_B68;
    int field_B6C;
};

VALIDATE_SIZE(cElectromagneticBarrier, 0xB70);