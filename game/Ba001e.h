#pragma once

#include <BehaviorBa.h>

class Ba001e : public BehaviorBa
{
public:

    Ba001e()
    {
        MAKE_CALL(shared::base + 0x6B04B0, void(__thiscall *)(Ba001e *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B10);
};

VALIDATE_SIZE(Ba001e, 0xB30);