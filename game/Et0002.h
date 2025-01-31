#pragma once

#include <Behavior.h>

class Et0002 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    Et0002()
    {
        ((void(__thiscall *)(Et0002 *))(shared::base + 0x6A6960))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735220);
};

VALIDATE_SIZE(Et0002, 0x880);