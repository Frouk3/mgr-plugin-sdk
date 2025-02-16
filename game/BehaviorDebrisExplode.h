#pragma once

#include <BehaviorDebrisBase.h>

class BehaviorDebrisExplode : public BehaviorDebrisBase
{
public:

    BehaviorDebrisExplode()
    {
        ((void(__thiscall *)(BehaviorDebrisExplode *))(shared::base + 0x1DBF20))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735324);
};

VALIDATE_SIZE(BehaviorDebrisExplode, 0x970);