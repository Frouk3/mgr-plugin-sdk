#pragma once

#include <BehaviorDebrisObject.h>

class BehaviorDebrisZangekiBonus : public BehaviorDebrisObject
{
public:
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;

    BehaviorDebrisZangekiBonus()
    {
        ((void(__thiscall *)(BehaviorDebrisZangekiBonus *))(shared::base + 0x6C10E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x173531C);
};

VALIDATE_SIZE(BehaviorDebrisZangekiBonus, 0x9B0);