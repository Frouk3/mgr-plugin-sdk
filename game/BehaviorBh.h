#include "BehaviorBgBase.h"

class BehaviorBh : public BehaviorBgBase
{
public:
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;
    cEspControler field_AA0;
    cEspControler field_B50;
    int field_C00;
    int field_C04;
    int field_C08;
    int field_C0C;

    BehaviorBh()
    {
        ((void (__thiscall *)(BehaviorBh*))(shared::base + 0x6C7AB0))(this);
    };
};

VALIDATE_SIZE(BehaviorBh, 0xC10);