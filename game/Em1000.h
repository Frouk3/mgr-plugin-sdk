#pragma once

#include <Behavior.h>

class Em1000 : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em1000()
    {
        ((void(__thiscall *)(Em1000 *))(shared::base + 0x6A66E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17351DC);
};

VALIDATE_SIZE(Em1000, 0x880);