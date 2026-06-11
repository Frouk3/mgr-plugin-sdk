#pragma once

#include <Behavior.h>

class Em0048 : public Behavior
{
public:
    Em0048()
    {
        MAKE_CALL(shared::base + 0x6A60A0, void(__thiscall *)(Em0048*), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x1735428);
};

VALIDATE_SIZE(Em0048, 0x870);