#pragma once

#include <Behavior.h>

/// Unused class

class Bh0064 : public Behavior
{
public:

    Bh0064()
    {
        MAKE_CALL(shared::base + 0xE5C0, void(__thiscall *)(Bh0064 *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x1734B6C);
};

VALIDATE_SIZE(Bh0064, 0x870);