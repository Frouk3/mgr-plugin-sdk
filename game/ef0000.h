#pragma once

#include <Behavior.h>

class ef0000 : public Behavior
{
public:

    ef0000()
    {
        MAKE_CALL(shared::base + 0x6A6930, void(__thiscall *)(ef0000 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x177B378);
};

VALIDATE_SIZE(ef0000, 0x870);