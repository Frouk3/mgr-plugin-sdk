#pragma once

#include <Hw.h>

class cMsgCtrl
{
public:
    int field_4;
    int field_8;
    Hw::cTexture m_MsgTexture;
    int field_28;
    char field_2C;
    short field_2D;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;

    virtual ~cMsgCtrl() {};
};

VALIDATE_SIZE(cMsgCtrl, 0x44);

class cCkMsgDataManager
{
public:
    struct MsgData
    {
        int field_0;
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
        cMsgCtrl field_38;
        int field_7C;
        int field_80;
        int field_84;
        int field_88;
        int field_8C;
        cMsgCtrl field_90;
    };
public:
    int field_4;
    int field_8;
    cCkMsgDataManager::MsgData field_C[6];
    int field_504;
    int field_508;
    int field_50C;
    int field_510;
    int field_514;
    int field_518;
    int field_51C;
    Hw::cHeapPhysical field_520;
    Hw::cHeapPhysical field_990;
    int field_E00;
    int field_E04;
    int field_E08;
    int field_E0C;
    int field_E10;
    int field_E14;
    int field_E18;
    int field_E1C;
    int field_E20;
    int field_E24;
    int field_E28;
    int field_E2C;
    int field_E30;
    int field_E34;
    int field_E38;
    int field_E3C;
    int field_E40;
    int field_E44;
    int field_E48;
    int field_E4C;
    int field_E50;
    int field_E54;
    int field_E58;
    int field_E5C;
    int field_E60;
    int field_E64;
    int field_E68;
    int field_E6C;
    int field_E70;
    int field_E74;
    int field_E78;
    int field_E7C;
    int field_E80;
    int field_E84;
    int field_E88;
    int field_E8C;
    int field_E90;
    int field_E94;
    int field_E98;
    int field_E9C;
    int field_EA0;
    int field_EA4;
    int field_EA8;
    int field_EAC;
    int field_EB0;
    int field_EB4;
    int field_EB8;
    int field_EBC;
    int field_EC0;
    int field_EC4;
    int field_EC8;
    int field_ECC;
    int field_ED0;
    int field_ED4;
    int field_ED8;
    int field_EDC;
    int field_EE0;
    int field_EE4;
    int field_EE8;
    int field_EEC;
    int field_EF0;
    int field_EF4;
    int field_EF8;
    int field_EFC;
    int field_F00;
    int field_F04;
    int field_F08;
    int field_F0C;
    int field_F10;

    virtual ~cCkMsgDataManager(){};
};

VALIDATE_SIZE(cCkMsgDataManager, 0xF14);