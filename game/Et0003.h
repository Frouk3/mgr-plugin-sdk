#pragma once

#include <Behavior.h>

class Et0003 : public Behavior
{
public:
    EntityHandle field_870[30];
    int field_8E8;
    int field_8EC;

    Et0003()
    {
        ((void(__thiscall *)(Et0003 *))(shared::base + 0x6A6AE0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735240);
};

VALIDATE_SIZE(Et0003, 0x8F0);