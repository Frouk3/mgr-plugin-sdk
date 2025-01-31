#pragma once

#include <Behavior.h>

class BehaviorEmBody : public Behavior
{
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    BehaviorEmBody()
    {
        ((void(__thiscall *)(BehaviorEmBody *))(shared::base + 0x6A6180))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9CA0);
};

VALIDATE_SIZE(BehaviorEmBody, 0x880);