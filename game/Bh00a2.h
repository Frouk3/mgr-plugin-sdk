#pragma once

#include <Behavior.h>

class Bh00a2 : public Behavior
{
public:
    
    Bh00a2()
    {
        MAKE_CALL(shared::base + 0x777EA0, void(__thiscall *)(Bh00a2 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9D74);
};

VALIDATE_SIZE(Bh00a2, 0x870);