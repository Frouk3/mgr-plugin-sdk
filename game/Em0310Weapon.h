#pragma once

#include <BehaviorWeapon.h>

class Em0310Weapon : public BehaviorWeapon
{
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;

    Em0310Weapon()
    {
        ((void(__thiscall *)(Em0310Weapon *))(shared::base + 0x6A6470))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735144);
};

VALIDATE_SIZE(Em0310Weapon, 0x8D0);