#pragma once

#include <BehaviorBh.h>

class Bh0056 : public BehaviorBh
{
public:

    Bh0056()
    {
        ((void(__thiscall *)(Bh0056 *))(shared::base + 0xE050))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B68);
};

VALIDATE_SIZE(Bh0056, 0xC10);