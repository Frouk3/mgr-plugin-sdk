#pragma once

#include <BehaviorAppBase.h>

class BehaviorTest : public BehaviorAppBase
{
public:

    BehaviorTest()
    {
        ((void(__thiscall *)(BehaviorTest *))(shared::base + 0x6AB8A0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C88);
};

VALIDATE_SIZE(BehaviorTest, 0xA00);