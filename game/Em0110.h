#pragma once

#include <BehaviorEmBase.h>
#include <BehaviorDebrisBase.h>
#include <BehaviorWeapon.h>

class Em0110MoveCheckLinearCastCollector : public hkpAllCdPointCollector{};

class Em0110WeaponBase : public BehaviorWeapon
{
public: 
    struct WeaponData : BehaviorWeapon::WeaponData
    {
        int field_90;
        int field_94;
        int field_98;
        int field_9C;
        int field_A0;
        int field_A4;
        int field_A8;
        int field_AC;
    };
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    WeaponData m_WeaponData[5];

    Em0110WeaponBase()
    {
        ((void(__thiscall *)(Em0110WeaponBase *))(shared::base + 0x6A92F0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1734E88);
};

class Em0110Weapon : public Em0110WeaponBase
{
public:
    int field_C50;
    int field_C54;
    int field_C58;
    int field_C5C;
    int field_C60;
    int field_C64;
    int field_C68;
    int field_C6C;
    int field_C70;
    int field_C74;
    int field_C78;
    int field_C7C;
    int field_C80;
    int field_C84;
    int field_C88;
    int field_C8C;
    int field_C90;
    int field_C94;
    int field_C98;
    int field_C9C;
    int field_CA0;
    int field_CA4;
    int field_CA8;
    int field_CAC;
    int field_CB0;
    int field_CB4;
    int field_CB8;
    int field_CBC;
    int field_CC0;
    int field_CC4;
    int field_CC8;
    int field_CCC;
    int field_CD0;
    int field_CD4;
    int field_CD8;
    int field_CDC;
    EntityHandle field_CE0;
    int field_CE4;
    int field_CE8;
    int field_CEC;
    int field_CF0;
    int field_CF4;
    int field_CF8;
    int field_CFC;

    Em0110Weapon()
    {
        ((void(__thiscall *)(Em0110Weapon *))(shared::base + 0x6ADB50))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E84);
};

class Em0110_WeaponDebris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    Em0110_WeaponDebris()
    {
        ((void(__thiscall *)(Em0110_WeaponDebris*))(shared::base + 0x6AFDB0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734EA0);
};

class Em0110_Debris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;

    Em0110_Debris()
    {
        ((void(__thiscall *)(Em0110_Debris*))(shared::base + 0x6AFD20))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E9C);
};

class Em0110_ArmDebris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    Em0110_ArmDebris()
    {
        ((void(__thiscall *)(Em0110_ArmDebris*))(shared::base + 0x6AFC90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E98);
};

class Em0110Arm : public Behavior
{
public:
    int field_870;
    EntityHandle field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;

    Em0110Arm()
    {
        ((void(__thiscall *)(Em0110Arm *))(shared::base + 0x6A6550))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E90);
};

class Em0110CutWhip : public BehaviorWeapon
{
public:
    EntityHandle field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    WeaponData m_WeaponData;

    Em0110CutWhip()
    {
        ((void(__thiscall *)(Em0110CutWhip*))(shared::base + 0x6A64F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E8C);
};

class Em0110 : public BehaviorEmBase
{
public:
    int field_DC0;
    int field_DC4;
    float field_DC8;
    float field_DCC;
    float field_DD0;
    float field_DD4;
    float field_DD8;
    EntityHandle field_DDC;
    cEspControler field_DE0;
    cEspControler field_E90;
    cEspControler field_F40;
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
    EntityHandle field_1020;
    EntityHandle field_1024;
    EntityHandle field_1028;
    EntityHandle field_102C;
    EntityHandle field_1030[2];
    EntityHandle field_1038;
    EntityHandle field_103C;
    EntityHandle field_1040;
    EntityHandle field_1044;
    EntityHandle field_1048;
    EntityHandle field_104C;
    EntityHandle field_1050;
    EntityHandle field_1054;
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
    int field_11C0;
    int field_11C4;
    int field_11C8;
    int field_11CC;
    int field_11D0;
    int field_11D4;
    int field_11D8;
    int field_11DC;
    int field_11E0;
    int field_11E4;
    int field_11E8;
    int field_11EC;
    int field_11F0;
    int field_11F4;
    int field_11F8;
    int field_11FC;
    int field_1200;
    int field_1204;
    int field_1208;
    int field_120C;
    int field_1210;
    int field_1214;
    int field_1218;
    int field_121C;
    int field_1220;
    int field_1224;
    int field_1228;
    int field_122C;
    int field_1230;
    int field_1234;
    int field_1238;
    int field_123C;
    int field_1240;
    int field_1244;
    int field_1248;
    int field_124C;
    int field_1250;
    int field_1254;
    int field_1258;
    int field_125C;
    int field_1260;
    int field_1264;
    int field_1268;
    int field_126C;
    int field_1270;
    int field_1274;
    int field_1278;
    int field_127C;
    int field_1280;
    int field_1284;
    int field_1288;
    int field_128C;
    int field_1290;
    int field_1294;
    int field_1298;
    int field_129C;
    int field_12A0;
    int field_12A4;
    int field_12A8;
    int field_12AC;
    int field_12B0;
    int field_12B4;
    int field_12B8;
    int field_12BC;
    int field_12C0;
    int field_12C4;
    int field_12C8;
    int field_12CC;
    int field_12D0;
    int field_12D4;
    int field_12D8;
    int field_12DC;
    int field_12E0;
    int field_12E4;
    int field_12E8;
    int field_12EC;
    int field_12F0;
    int field_12F4;
    int field_12F8;
    int field_12FC;
    int field_1300;
    int field_1304;
    int field_1308;
    int field_130C;
    int field_1310;
    int field_1314;
    int field_1318;
    int field_131C;
    int field_1320;
    int field_1324;
    int field_1328;
    int field_132C;
    int field_1330;
    int field_1334;
    int field_1338;
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

    Em0110()
    {
        ((void(__thiscall *)(Em0110*))(shared::base + 0x6AD8F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E80);
};

VALIDATE_SIZE(Em0110WeaponBase::WeaponData, 0xB0);
VALIDATE_SIZE(Em0110WeaponBase, 0xC50);
VALIDATE_SIZE(Em0110Weapon, 0xD00);
VALIDATE_SIZE(Em0110CutWhip, 0x960);
VALIDATE_SIZE(Em0110Arm, 0x890);
VALIDATE_SIZE(Em0110_WeaponDebris, 0x980);
VALIDATE_SIZE(Em0110_Debris, 0x9A0);
VALIDATE_SIZE(Em0110_ArmDebris, 0x980);
VALIDATE_SIZE(Em0110, 0x1370);