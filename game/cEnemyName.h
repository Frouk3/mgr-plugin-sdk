#pragma once

#include <cCustomObjCtrlManager.h>

class cEnemyNameParts : public cCustomObjCtrlManager
{
public:
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    int field_64;
    float field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
};

class cEnemyName
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
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;

    virtual ~cEnemyName() {};
};

class cEnemyNameBase : public cCustomObjWorkBase{};