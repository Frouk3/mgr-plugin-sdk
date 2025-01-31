#pragma once

#include <Behavior.h>

class Em0310Shield : public Behavior
{
public:
    int field_870;
    EntityHandle field_874;
    int field_878;
    int field_87C;
    CollisionAttackData::AttackData m_AttackData;
    int field_980;
    float field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;

    Em0310Shield()
    {
        ((void(__thiscall *)(Em0310Shield *))(shared::base + 0x6A6370))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x173514C);
};

VALIDATE_SIZE(Em0310Shield, 0x9B0);