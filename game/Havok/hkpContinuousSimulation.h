#pragma once

#include <hkpSimulation.h>

class hkpContinuousSimulation : public hkpSimulation
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
};

VALIDATE_SIZE(hkpContinuousSimulation, 0x4C);