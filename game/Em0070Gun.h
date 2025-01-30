#pragma once

#include <BehaviorWeapon.h>

class Em0070Gun : public BehaviorWeapon
{
public:
    int field_8C0;
    EntityHandle field_8C4;
    int field_8C8;
    int field_8CC;

    Em0070Gun()
    {
        ((void(__thiscall *)(Em0070Gun *))(shared::base + 0x6A6780))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734D5C);
};

VALIDATE_SIZE(Em0070Gun, 0x8D0);