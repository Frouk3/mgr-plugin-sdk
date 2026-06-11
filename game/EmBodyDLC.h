#pragma once

#include <BehaviorEmBody.h>

class EmBodyDLC : public BehaviorEmBody
{
public:

    EmBodyDLC()
    {
        MAKE_CALL(shared::base + 0x6B20E0, void(__thiscall *)(EmBodyDLC *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C40);
};

VALIDATE_SIZE(EmBodyDLC, 0x880);