#pragma once

#include <Behavior.h>

class BehaviorBgBase : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    cEspControler *field_888;
    int field_88C;
    int field_890;
    int field_894;
    int m_AutoSePlay;
    int m_SeId;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int m_CutZanMode;
    int field_8B0;
    float field_8B4;
    int field_8B8;
    int field_8BC;
    cVec4 field_8C0;
    float field_8D0;
    float field_8D4;
    float field_8D8;
    float field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    CollisionAttackData::AttackData field_8F0;
    float field_9F0;
    int field_9F4;
    BOOL m_EnemyNoBreak;
    int field_9FC;
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    int field_A40;
    int field_A44;
    float m_ZanTargetEnableRange;
    float m_ZanTargetRad;
    float field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    EntityHandle field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;

    BehaviorBgBase()
    {
        ((void (__thiscall *)(BehaviorBgBase *))(shared::base + 0x6A4D50))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9C28);
};

VALIDATE_SIZE(BehaviorBgBase, 0xA70);