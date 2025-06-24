#pragma once

#include <lib.h>

struct RigidBodyList
{
    struct ConnectMap
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
    };

    int field_0;
    lib::StaticArray<ConnectMap, 256> field_4;
    lib::StaticArray<ConnectMap, 256> field_1814;
    int field_3024;
    int field_3028;
    int field_302C;
    int field_3030;
    int field_3034;
    int field_3038;
    int field_303C;
    int field_3040;
    int field_3044;
    int field_3048;
    int field_304C;
    int field_3050;
    int field_3054;
    int field_3058;
    int field_305C;
    int field_3060;
    int field_3064;
    int field_3068;
    int field_306C;
    int field_3070;
    int field_3074;
    int field_3078;
    int field_307C;
};