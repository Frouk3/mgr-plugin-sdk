#pragma once

#include <EmBaseDLC.h>
#include <RayArmorDebris.h>
#include <WpBaseDLC.h>

class Em0130Weapon : public WpBaseDLC
{
public:
    EntityHandle field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;

    Em0130Weapon()
    {
        ((void(__thiscall *)(Em0130Weapon *))(shared::base + 0x6B59C0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735514);
};

class Em0130Face : public Behavior
{
public:

    Em0130Face()
    {
        ((void(__thiscall *)(Em0130Face *))(shared::base + 0x6A6F40))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance *)(shared::base + 0x173551C);
};

class Em0130Debris : public RayArmorDebris
{
public:
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;

    Em0130Debris()
    {
        ((void(__thiscall *)(Em0130Debris *))(shared::base + 0x6B5A70))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735518);
};

class Em0130 : public EmBaseDLC
{
public:
    int field_E8C;
    int field_E90;
    int field_E94;
    int field_E98;
    int field_E9C;
    int field_EA0;
    EntityHandle field_EA4;
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
    EntityHandle field_F64[15];
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
    int field_10C0;
    int field_10C4;
    int field_10C8;
    int field_10CC;
    int field_10D0;
    int field_10D4;
    int field_10D8;
    int field_10DC;
    int field_10E0;
    int field_10E4;
    int field_10E8;
    int field_10EC;
    int field_10F0;
    int field_10F4;
    int field_10F8;
    int field_10FC;
    int field_1100;
    int field_1104;
    int field_1108;
    int field_110C;
    int field_1110;
    int field_1114;
    int field_1118;
    int field_111C;
    int field_1120;
    int field_1124;
    int field_1128;
    int field_112C;
    int field_1130;
    int field_1134;
    int field_1138;
    int field_113C;
    int field_1140;
    int field_1144;
    int field_1148;
    int field_114C;
    int field_1150;
    int field_1154;
    int field_1158;
    int field_115C;
    int field_1160;
    int field_1164;
    int field_1168;
    int field_116C;
    int field_1170;
    int field_1174;
    int field_1178;
    int field_117C;
    int field_1180;
    int field_1184;
    int field_1188;
    int field_118C;
    int field_1190;
    int field_1194;
    int field_1198;
    int field_119C;
    int field_11A0;
    int field_11A4;
    int field_11A8;
    int field_11AC;
    int field_11B0;
    int field_11B4;
    int field_11B8;
    int field_11BC;
    cEspControler field_11C0;
    cEspControler field_1270;
    int field_1320;
    int field_1324;
    int field_1328;
    int field_132C;
    int field_1330;
    int field_1334;
    float field_1338;
    int field_133C;
    int field_1340;
    int field_1344;
    int field_1348;
    int field_134C;
    int field_1350;
    int field_1354;
    int field_1358;
    int field_135C;
    int field_1360;
    int field_1364;
    int field_1368;
    int field_136C;
    int field_1370;
    int field_1374;
    int field_1378;
    int field_137C;
    int field_1380;
    int field_1384;
    int field_1388;
    int field_138C;
    int field_1390;
    int field_1394;
    int field_1398;
    int field_139C;
    int field_13A0;
    int field_13A4;
    int field_13A8;
    int field_13AC;
    int field_13B0;
    int field_13B4;
    int field_13B8;
    int field_13BC;
    int field_13C0;
    int field_13C4;
    int field_13C8;
    int field_13CC;
    int field_13D0;
    EntityHandle field_13D4;
    EntityHandle field_13D8;
    int field_13DC;
    int field_13E0;
    int field_13E4;
    int field_13E8;
    int field_13EC;
    int field_13F0;
    int field_13F4;
    int field_13F8;
    int field_13FC;

    Em0130()
    {
        ((void(__thiscall *)(Em0130*))(shared::base + 0x6B57D0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735510);
};

VALIDATE_SIZE(Em0130Weapon, 0x8D0);
VALIDATE_SIZE(Em0130Face, 0x870);
VALIDATE_SIZE(Em0130Debris, 0x9A0);
VALIDATE_SIZE(Em0130, 0x1400);