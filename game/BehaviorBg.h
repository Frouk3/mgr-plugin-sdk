#pragma once

#include <BehaviorBgBase.h>

class BehaviorBg : public BehaviorBgBase
{
public:

    BehaviorBg()
    {
        ((void(__thiscall *)(BehaviorBg* ))(shared::base + 0x6A6FC0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C50);
};

VALIDATE_SIZE(BehaviorBg, 0xA70);