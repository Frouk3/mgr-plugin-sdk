#pragma once

#include <Behavior.h>

class Em0041 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    float field_884;
    float field_888;
    float field_88C;
    float field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    float field_8B0;
    float field_8B4;
    float field_8B8;
    float field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    float field_8D0;
    float field_8D4;
    float field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1734C54);
};

VALIDATE_SIZE(Em0041, 0x900);