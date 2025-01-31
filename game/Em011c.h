#pragma once

#include <Behavior.h>

class Em011c : public Behavior
{
public:

    Em011c()
    {
        ((void(__thiscall *)(Em011c *))(shared::base + 0x6A65A0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734EA4);
};

VALIDATE_SIZE(Em011c, 0x870);