#pragma once
#include <Pl0000.h>

class PlBaseDLC : public Pl0000
{
public:
    int field_5400;
};

VALIDATE_SIZE(PlBaseDLC, 0x5404);