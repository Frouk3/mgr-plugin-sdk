#pragma once

#include <BehaviorWeapon.h>

class Em01a0Sai : public BehaviorWeapon
{
public:
    EntityHandle field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;

    Em01a0Sai()
    {
        ((void(__thiscall *)(Em01a0Sai *))(shared::base + 0x6A65D0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734F50);
};

VALIDATE_SIZE(Em01a0Sai, 0x8D0);