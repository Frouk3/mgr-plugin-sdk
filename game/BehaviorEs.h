#pragma once

#include <Behavior.h>

class BehaviorEs : public Behavior
{
public:

    BehaviorEs()
    {
        MAKE_CALL(shared::base + 0x6A6720, void(__thiscall *)(BehaviorEs *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x17E9C70);
};

VALIDATE_SIZE(BehaviorEs, 0x870);