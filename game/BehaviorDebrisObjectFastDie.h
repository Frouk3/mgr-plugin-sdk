#pragma once

#include <Behavior.h>

class BehaviorDebrisObjectFastDie : public Behavior
{
public:

    BehaviorDebrisObjectFastDie()
    {
        MAKE_CALL(shared::base + 0x6A6C70, void(__thiscall *)(BehaviorDebrisObjectFastDie *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735318);
};

VALIDATE_SIZE(BehaviorDebrisObjectFastDie, 0x870);