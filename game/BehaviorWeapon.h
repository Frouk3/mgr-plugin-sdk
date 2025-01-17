#pragma once

#include <Behavior.h>

class BehaviorWeapon : public Behavior
{
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
};

VALIDATE_SIZE(BehaviorWeapon, 0x8C0);