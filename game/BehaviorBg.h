#pragma once

#include <BehaviorBgBase.h>

class BehaviorBg : public BehaviorBgBase
{
public:

    BehaviorBg()
    {
        MAKE_CALL(shared::base + 0x6A6FC0, void(__thiscall *)(BehaviorBg *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C50);
};

VALIDATE_SIZE(BehaviorBg, 0xA70);