#pragma once

#include <BehaviorBh.h>

class Bh0016 : public BehaviorBh
{
public:

    Bh0016()
    {
        MAKE_CALL(shared::base + 0x6AFED0, void(__thiscall *)(Bh0016 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B64);
};

VALIDATE_SIZE(Bh0016, 0xC10);