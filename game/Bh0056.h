#pragma once

#include <BehaviorBh.h>

class Bh0056 : public BehaviorBh
{
public:

    Bh0056()
    {
        MAKE_CALL(shared::base + 0xE050, void(__thiscall *)(Bh0056 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B68);
};

VALIDATE_SIZE(Bh0056, 0xC10);