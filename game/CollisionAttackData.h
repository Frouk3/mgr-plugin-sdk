#pragma once

#include <CollisionUserData.h>
#include <shared.h>

class CollisionAttackData : public CollisionUserData
{
public:
    struct HitData : public CollisionUserData::HitData
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        short field_10;
        int field_14;
        EntityHandle field_18;
        int field_1C;
        float field_20;
        float field_24;
        float field_28;
        int field_2C;
        float field_30;
        int field_34;
        int field_38;
        int field_3C;
        float field_40;
        float field_44;
        float field_48;
        float field_4C;
        float field_50;
        float field_54;
        float field_58;
        float field_5C;
        float field_60;
        float field_64;
        float field_68;
        float field_6C;
        float field_70;
        float field_74;
        float field_78;
        float field_7C;
        int field_80;
        short field_84;
        int field_88;
        int field_8C;
        int field_90;
        int field_94;
        int field_98;
        int field_9C;
        float field_A0;
        float field_A4;
        float field_A8;
        float field_AC;
        float field_B0;
        float field_B4;
        float field_B8;
        float field_BC;
        float field_C0;
        float field_C4;
        float field_C8;
        float field_CC;
        float field_D0;
        float field_D4;
        float field_D8;
        float field_DC;
        float field_E0;
        float field_E4;
        int field_E8;
        int field_EC;
        int field_F0;
        int field_F4;
        int field_F8;
        int field_FC;

        HitData()
        {
            ((void(__thiscall *)(HitData*))(shared::base + 0x105D0))(this);
        }
    };
public:
    int field_C;
    HitData m_CollisionDataContainer;

    CollisionAttackData()
    {
        ((void (__thiscall *)(CollisionAttackData *))(shared::base + 0x973030))(this);
    }
};

VALIDATE_SIZE(CollisionAttackData, 0x110);