#pragma once

#include <Behavior.h>

class Em0110Arm : public Behavior
{
public:
    int field_870;
    EntityHandle field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;

    Em0110Arm()
    {
        ((void(__thiscall *)(Em0110Arm *))(shared::base + 0x6A6550))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E90);
};

VALIDATE_SIZE(Em0110Arm, 0x890);