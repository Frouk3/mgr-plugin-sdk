#pragma once

#include <BehaviorBa.h>

class Ba0017 : public BehaviorBa
{
public:
    CollisionAttackData::HitData field_B30[64];

    Ba0017()
    {
        ((void(__thiscall *)(Ba0017 *))(shared::base + 0x6B0040))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B0C);
};

VALIDATE_SIZE(Ba0017, 0x4B30);