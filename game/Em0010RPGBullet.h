#pragma once

#include <Behavior.h>

class Em0010RPGBullet : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em0010RPGBullet()
    {
        ((void(__thiscall *)(Em0010RPGBullet *))(shared::base + 0x6A68D0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9D30);
};

VALIDATE_SIZE(Em0010RPGBullet, 0x880);