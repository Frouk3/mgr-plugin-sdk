#pragma once

#include <Behavior.h>

class BehaviorEmBody : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    BehaviorEmBody()
    {
        MAKE_CALL(shared::base + 0x6A6180, void(__thiscall *)(BehaviorEmBody *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9CA0);
};

VALIDATE_SIZE(BehaviorEmBody, 0x880);