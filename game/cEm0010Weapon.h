#pragma once

#include <BehaviorWeapon.h>

class cEm0010Weapon : public BehaviorWeapon
{
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    EntityHandle field_8CC;

    cEm0010Weapon()
    {
        ((void(__thiscall *)(cEm0010Weapon *))(shared::base + 0x6A6830))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D28);
};

VALIDATE_SIZE(cEm0010Weapon, 0x8D0);