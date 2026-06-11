#pragma once

#include <Behavior.h>

class BehaviorDestructionImpact : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    BehaviorDestructionImpact()
    {
        MAKE_CALL(shared::base + 0x6A6800, void(__thiscall *)(BehaviorDestructionImpact *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x17354B4);
};

VALIDATE_SIZE(BehaviorDestructionImpact, 0x880);