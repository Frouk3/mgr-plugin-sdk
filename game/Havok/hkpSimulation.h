#pragma once

#include <hkReferencedObject.h>

class hkpSimulation : public hkReferencedObject
{
public:
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

VALIDATE_SIZE(hkpSimulation, 0x30);