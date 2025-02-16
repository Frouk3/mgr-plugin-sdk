#pragma once

#include <GimmickBehaviorBase.h>

class cElectromagneticBarrierNode : public GimmickBehaviorBase
{
public:
    float field_B40;
    float field_B44;
    float field_B48;
    float field_B4C;
    float field_B50;
    float field_B54;
    float field_B58;
    float field_B5C;
    float field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
};

VALIDATE_SIZE(cElectromagneticBarrierNode, 0xB70);