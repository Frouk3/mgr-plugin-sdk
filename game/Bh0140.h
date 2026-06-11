#pragma once

#include <BehaviorBh.h>

class Bh0140 : public BehaviorBh
{
public:

    Bh0140()
    {
        MAKE_CALL(shared::base + 0x6AE9D0, void(__thiscall *)(Bh0140 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17351D8);
};

VALIDATE_SIZE(Bh0140, 0xC10);