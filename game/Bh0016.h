#pragma once

#include <BehaviorBh.h>

class Bh0016 : public BehaviorBh
{
public:

    Bh0016()
    {
        ((void(__thiscall *)(Bh0016 *))(shared::base + 0x6AFED0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B64);
};

VALIDATE_SIZE(Bh0016, 0xC10);