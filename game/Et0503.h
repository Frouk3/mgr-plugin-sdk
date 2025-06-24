#pragma once

#include <Behavior.h>

class Et0503 : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Et0503()
    {
        ((void(__thiscall *)(Et0503 *))(shared::base + 0x6A6D30))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17352B8);
};

VALIDATE_SIZE(Et0503, 0x880);