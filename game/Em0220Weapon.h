#pragma once

#include <BehaviorWeapon.h>

class Em0220Weapon : public BehaviorWeapon
{
public:
    EntityHandle field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;

    Em0220Weapon()
    {
        ((void(__thiscall *)(Em0220Weapon *))(shared::base + 0x6A6310))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735008);
};

VALIDATE_SIZE(Em0220Weapon, 0x900);