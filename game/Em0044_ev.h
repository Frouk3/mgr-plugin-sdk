#pragma once

#include <Behavior.h>

class Em0044_ev : public Behavior
{
public:

    Em0044_ev()
    {
        MAKE_CALL(shared::base + 0x6A6290, void(__thiscall *)(Em0044_ev *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x173542C);
};

VALIDATE_SIZE(Em0044_ev, 0x870);