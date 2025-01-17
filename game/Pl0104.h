#pragma once

#include <Behavior.h>

class Pl0104 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
};

VALIDATE_SIZE(Pl0104, 0x880);