#include "BehaviorBgBase.h"

class BehaviorBa : public BehaviorBgBase
{
public:
    cEspControler field_A70;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;

    BehaviorBa()
    {
        ((void (__thiscall *)(BehaviorBa *))(shared::base + 0x6C3E80))(this);
    }
};

VALIDATE_SIZE(BehaviorBa, 0xB30);