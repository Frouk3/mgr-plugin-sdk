#pragma once

#include <Behavior.h>

class BehaviorDebrisObjectFastDie : public Behavior
{
public:

    BehaviorDebrisObjectFastDie()
    {
        ((void (__thiscall *)(BehaviorDebrisObjectFastDie *))(shared::base + 0x6A6C70))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735318);
};

VALIDATE_SIZE(BehaviorDebrisObjectFastDie, 0x870);