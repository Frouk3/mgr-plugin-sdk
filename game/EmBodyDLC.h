#pragma once

#include <BehaviorEmBody.h>

class EmBodyDLC : public BehaviorEmBody
{
public:

    EmBodyDLC()
    {
        ((void(__thiscall *)(EmBodyDLC *))(shared::base + 0x6B20E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C40);
};

VALIDATE_SIZE(EmBodyDLC, 0x880);