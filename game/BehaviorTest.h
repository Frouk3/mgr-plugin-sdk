#pragma once

#include <BehaviorAppBase.h>

class BehaviorTest : public BehaviorAppBase
{
public:

    BehaviorTest()
    {
        MAKE_CALL(shared::base + 0x6AB8A0, void(__thiscall *)(BehaviorTest *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C88);
};

VALIDATE_SIZE(BehaviorTest, 0xA00);