#pragma once

#include <Behavior.h>

class Em0045 : public Behavior
{
public:
    EntityHandle field_870[2];
    int field_878;
    int field_87C;
    float field_880;
    float field_884;
    float field_888;
    float field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;

    Em0045()
    {
        ((void(__thiscall *)(Em0045 *))(shared::base + 0x6A62C0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1734C60);
};

VALIDATE_SIZE(Em0045, 0x8C0);