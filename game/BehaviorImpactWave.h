#pragma once

#include <Behavior.h>

class BehaviorImpactWave : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    BehaviorImpactWave()
    {
        ((void(__thiscall *)(BehaviorImpactWave *))(shared::base + 0x6A67D0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17354B8);
};

VALIDATE_SIZE(BehaviorImpactWave, 0x880);