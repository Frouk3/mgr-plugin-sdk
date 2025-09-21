#pragma once

#include <BehaviorBa.h>

class Ba0015 : public BehaviorBa
{
public:
    CollisionAttackData::HitData field_B30[64];

    Ba0015()
    {
        ((void(__thiscall *)(Ba0015 *))(shared::base + 0x6AFFD0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B08);
};

VALIDATE_SIZE(Ba0015, 0x4B30);