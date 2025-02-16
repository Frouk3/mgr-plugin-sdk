#pragma once

#include <Behavior.h>

class Em0042 : public Behavior
{
public:
    Animation::HandIk field_870[3];
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;

    Em0042()
    {
        ((void(__thiscall *)(Em0042 *))(shared::base + 0x6A6240))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1734C58);
};

VALIDATE_SIZE(Em0042, 0xB70);