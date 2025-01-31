#pragma once

#include <Behavior.h>

class Et4000 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    Et4000()
    {
        ((void(__thiscall *)(Et4000*))(shared::base + 0x6A6A50))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17352C0);
};

VALIDATE_SIZE(Et4000, 0x880);