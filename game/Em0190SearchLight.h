#pragma once

#include <Behavior.h>

class Em0190SearchLight : public Behavior
{
public:

    Em0190SearchLight()
    {
        ((void(__thiscall *)(Em0190SearchLight*))(shared::base + 0x6A69C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734F28);
};

VALIDATE_SIZE(Em0190SearchLight, 0x870);