#pragma once

#include <Behavior.h>

class BehaviorWeapon : public Behavior
{
public:
    struct WeaponData
    {
        EntityHandle field_0;
        int field_4;
        int field_8;
        int field_C;
        float field_10;
        float field_14;
        float field_18;
        float field_1C;
        float field_20;
        float field_24;
        float field_28;
        float field_2C;
        float field_30;
        float field_34;
        int field_38;
        float field_3C;
        int field_40;
        float field_44;
        float field_48;
        int field_4C;
        int field_50;
        int field_54;
        int field_58;
        int field_5C;
        float field_60;
        float field_64;
        float field_68;
        float field_6C;
        float field_70;
        float field_74;
        float field_78;
        float field_7C;
        int field_80;
        int field_84;
        int field_88;
        int field_8C;

        WeaponData()
        {
            ((void(__thiscall *)(WeaponData *))(shared::base + 0x68F0E0))(this);
        }
    };
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;

    BehaviorWeapon()
    {
        ((void(__thiscall *)(BehaviorWeapon *))(shared::base + 0x6A4AD0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C2C);
};

VALIDATE_SIZE(BehaviorWeapon::WeaponData, 0x90);
VALIDATE_SIZE(BehaviorWeapon, 0x8C0);