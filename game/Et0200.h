#pragma once

#include <Behavior.h>

class Et0200 : public Behavior
{
public:

    Et0200()
    {
        ((void(__thiscall *)(Et0200 *))(shared::base + 0x6A69F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17352B4);
};

VALIDATE_SIZE(Et0200, 0x870);