#pragma once

#include <Behavior.h>

class BehaviorEs : public Behavior
{
public:

    BehaviorEs()
    {
        ((void(__thiscall *)(BehaviorEs *))(shared::base + 0x6A6720))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9C70);
};

VALIDATE_SIZE(BehaviorEs, 0x870);