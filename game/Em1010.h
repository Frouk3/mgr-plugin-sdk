#pragma once

#include <BehaviorEmBase.h>

class Em1010 : public BehaviorEmBase
{
public:
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;
    int field_DD0;
    int field_DD4;
    int field_DD8;
    int field_DDC;
    int field_DE0;
    int field_DE4;
    int field_DE8;
    int field_DEC;
    int field_DF0;
    int field_DF4;
    int field_DF8;
    int field_DFC;
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
    int field_F14;
    int field_F18;
    int field_F1C;
    int field_F20;
    int field_F24;
    int field_F28;
    int field_F2C;
    int field_F30;
    int field_F34;
    int field_F38;
    int field_F3C;
    int field_F40;
    int field_F44;
    int field_F48;
    int field_F4C;
    int field_F50;
    int field_F54;
    int field_F58;
    int field_F5C;
    int field_F60;
    int field_F64;
    int field_F68;
    int field_F6C;
    int field_F70;
    int field_F74;
    int field_F78;
    int field_F7C;
    int field_F80;
    int field_F84;
    int field_F88;
    int field_F8C;
    int field_F90;
    int field_F94;
    int field_F98;
    int field_F9C;
    int field_FA0;
    int field_FA4;
    int field_FA8;
    int field_FAC;
    int field_FB0;
    int field_FB4;
    int field_FB8;
    int field_FBC;
    int field_FC0;
    int field_FC4;
    int field_FC8;
    int field_FCC;
    int field_FD0;
    int field_FD4;
    int field_FD8;
    int field_FDC;
    int field_FE0;
    int field_FE4;
    int field_FE8;
    int field_FEC;
    int field_FF0;
    int field_FF4;
    int field_FF8;
    int field_FFC;
    int field_1000;
    int field_1004;
    int field_1008;
    int field_100C;
    int field_1010;
    int field_1014;
    int field_1018;
    int field_101C;
    int field_1020;
    int field_1024;
    int field_1028;
    int field_102C;
    int field_1030;
    int field_1034;
    int field_1038;
    int field_103C;
    int field_1040;
    int field_1044;
    int field_1048;
    int field_104C;
    int field_1050;
    int field_1054;
    int field_1058;
    int field_105C;
    int field_1060;
    int field_1064;
    int field_1068;
    int field_106C;
    int field_1070;
    int field_1074;
    int field_1078;
    int field_107C;
    int field_1080;
    int field_1084;
    int field_1088;
    int field_108C;
    int field_1090;
    int field_1094;
    int field_1098;
    int field_109C;
    int field_10A0;
    int field_10A4;
    int field_10A8;
    int field_10AC;
    int field_10B0;
    int field_10B4;
    int field_10B8;
    int field_10BC;
    cEspControler field_10C0;

    Em1010()
    {
        ((void(__thiscall *)(Em1010*))(shared::base + 0x6AEC40))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17351E0);
};

VALIDATE_SIZE(Em1010, 0x1170);