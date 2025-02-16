#pragma once

#include <Behavior.h>

class Bh00a2 : public Behavior
{
public:
    
    Bh00a2()
    {
        ((void(__thiscall *)(Bh00a2*))(shared::base + 0x777EA0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D74);
};

VALIDATE_SIZE(Bh00a2, 0x870);