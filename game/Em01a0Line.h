#pragma once

#include <Behavior.h>

class Em01a0Line : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    EntityHandle field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    cEspControler field_8B0;

    Em01a0Line()
    {
        ((void(__thiscall *)(Em01a0Line *))(shared::base + 0x6A6620))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734F54);
};

VALIDATE_SIZE(Em01a0Line, 0x960);