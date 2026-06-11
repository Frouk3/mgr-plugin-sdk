#pragma once

#include <BehaviorDebrisBase.h>

class BehaviorDebrisExplode : public BehaviorDebrisBase
{
public:

    BehaviorDebrisExplode()
    {
        MAKE_CALL(shared::base + 0x1DBF20, void(__thiscall *)(BehaviorDebrisExplode *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x1735324);
};

VALIDATE_SIZE(BehaviorDebrisExplode, 0x970);