#pragma once

#include <BehaviorBa.h>

class Ba001e : public BehaviorBa
{
public:

    Ba001e()
    {
        ((void(__thiscall *)(Ba001e *))(shared::base + 0x6B04B0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B10);
};

VALIDATE_SIZE(Ba001e, 0xB30);