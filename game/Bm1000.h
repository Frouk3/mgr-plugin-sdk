#pragma once

#include <BehaviorBm.h>

class Bm1000 : public BehaviorBm
{
public:

    Bm1000()
    {
        MAKE_CALL(shared::base + 0x6B0320, void(__thiscall *)(Bm1000 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734BE8);
};

VALIDATE_SIZE(Bm1000, 0xB40);