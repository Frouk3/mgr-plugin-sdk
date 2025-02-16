#pragma once

#include <Behavior.h>

class ef0000 : public Behavior
{
public:

    ef0000()
    {
        ((void(__thiscall *)(ef0000 *))(shared::base + 0x6A6930))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x177B378);
};

VALIDATE_SIZE(ef0000, 0x870);