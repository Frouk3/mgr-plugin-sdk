#pragma once

#include <Behavior.h>

class Pl0012 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    cEspControler field_880;
    int field_930;
    float field_934;
    int field_938;
    int field_93C;
};

VALIDATE_SIZE(Pl0012, 0x940);