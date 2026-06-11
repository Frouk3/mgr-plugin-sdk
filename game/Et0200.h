#pragma once

#include <Behavior.h>

class Et0200 : public Behavior
{
public:

    Et0200()
    {
        MAKE_CALL(shared::base + 0x6A69F0, void(__thiscall *)(Et0200 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17352B4);
};

VALIDATE_SIZE(Et0200, 0x870);