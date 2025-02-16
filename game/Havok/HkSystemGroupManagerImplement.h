#pragma once

#include <HkSystemGroupManager.h>
#include <shared.h>

class HkSystemGroupManagerImplement : public HkSystemGroupManager
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;

    static inline HkSystemGroupManagerImplement* &ms_Instance = *(HkSystemGroupManagerImplement**)(shared::base + 0x1735DB8);
};