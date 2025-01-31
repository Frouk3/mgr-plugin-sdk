#pragma once

#include <Behavior.h>

class Em060c : public Behavior
{
public:

    Em060c()
    {
        ((void(__thiscall *)(Em060c *))(shared::base + 0x6A61C0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17351A4);
};

VALIDATE_SIZE(Em060c, 0x870);