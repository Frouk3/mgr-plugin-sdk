#pragma once

#include <BehaviorEmBase.h>

class Em0500 : public BehaviorEmBase
{
public:
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;

    Em0500()
    {
        ((void(__thiscall *)(Em0500*))(shared::base + 0x6AE730))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735184);
};

VALIDATE_SIZE(Em0500, 0xDD0);