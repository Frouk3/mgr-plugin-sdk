#pragma once

#include <BehaviorEmBase.h>
#include <BehaviorDebrisBase.h>
#include <BehaviorBgBase.h>
#include <BehaviorWeapon.h>

class Em0310 : public BehaviorEmBase
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
    cEspControler field_E20;
    cEspControler field_ED0;
    cEspControler field_F80;
    cEspControler field_1030;
    int field_10E0;
    int field_10E4;
    int field_10E8;
    EntityHandle field_10EC;
    EntityHandle field_10F0;
    EntityHandle field_10F4;
    EntityHandle field_10F8;
    EntityHandle field_10FC;
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
    int field_13D4;
    int field_13D8;
    int field_13DC;
    int field_13E0;
    int field_13E4;
    int field_13E8;
    int field_13EC;
    int field_13F0;
    int field_13F4;
    int field_13F8;
    int field_13FC;
    int field_1400;
    int field_1404;
    int field_1408;
    int field_140C;
    int field_1410;
    int field_1414;
    int field_1418;
    int field_141C;
    int field_1420;
    int field_1424;
    int field_1428;
    int field_142C;
    int field_1430;
    int field_1434;
    int field_1438;
    int field_143C;
    int field_1440;
    int field_1444;
    int field_1448;
    int field_144C;
    int field_1450;
    int field_1454;
    int field_1458;
    int field_145C;
    int field_1460;
    int field_1464;
    int field_1468;
    int field_146C;
    int field_1470;
    int field_1474;
    int field_1478;
    int field_147C;
    int field_1480;
    int field_1484;
    int field_1488;
    int field_148C;
    int field_1490;
    int field_1494;
    int field_1498;
    int field_149C;
    int field_14A0;
    int field_14A4;
    int field_14A8;
    int field_14AC;
    int field_14B0;
    int field_14B4;
    int field_14B8;
    int field_14BC;
    int field_14C0;
    int field_14C4;
    int field_14C8;
    int field_14CC;
    int field_14D0;
    int field_14D4;
    int field_14D8;
    int field_14DC;
    int field_14E0;
    int field_14E4;
    int field_14E8;
    int field_14EC;
    int field_14F0;
    int field_14F4;
    int field_14F8;
    int field_14FC;
    int field_1500;
    int field_1504;
    int field_1508;
    int field_150C;
    int field_1510;
    int field_1514;
    int field_1518;
    int field_151C;
    int field_1520;
    int field_1524;
    int field_1528;
    int field_152C;
    int field_1530;
    int field_1534;
    int field_1538;
    int field_153C;
    int field_1540;
    int field_1544;
    int field_1548;
    int field_154C;
    int field_1550;
    int field_1554;
    int field_1558;
    int field_155C;
    int field_1560;
    int field_1564;
    int field_1568;
    int field_156C;
    int field_1570;
    int field_1574;
    int field_1578;
    int field_157C;
    int field_1580;
    int field_1584;
    int field_1588;
    int field_158C;
    int field_1590;
    int field_1594;
    int field_1598;
    int field_159C;
    int field_15A0;
    int field_15A4;
    int field_15A8;
    int field_15AC;
    int field_15B0;
    int field_15B4;
    int field_15B8;
    int field_15BC;
    int field_15C0;
    int field_15C4;
    int field_15C8;
    int field_15CC;
    int field_15D0;
    int field_15D4;
    int field_15D8;
    int field_15DC;
    int field_15E0;
    int field_15E4;
    int field_15E8;
    int field_15EC;
    int field_15F0;
    int field_15F4;
    int field_15F8;
    int field_15FC;
    int field_1600;
    int field_1604;
    int field_1608;
    int field_160C;
    int field_1610;
    int field_1614;
    int field_1618;
    int field_161C;
    int field_1620;
    int field_1624;
    int field_1628;
    int field_162C;
    int field_1630;
    int field_1634;
    int field_1638;
    int field_163C;
    int field_1640;
    int field_1644;
    int field_1648;
    int field_164C;
    int field_1650;
    int field_1654;
    int field_1658;
    int field_165C;
    int field_1660;
    int field_1664;
    int field_1668;
    int field_166C;
    int field_1670;
    int field_1674;
    int field_1678;
    int field_167C;
    int field_1680;
    int field_1684;
    int field_1688;
    int field_168C;
    int field_1690;
    int field_1694;
    int field_1698;
    int field_169C;
    int field_16A0;
    int field_16A4;
    int field_16A8;
    int field_16AC;
    int field_16B0;
    int field_16B4;
    int field_16B8;
    int field_16BC;
    int field_16C0;
    int field_16C4;
    int field_16C8;
    int field_16CC;
    int field_16D0;
    int field_16D4;
    int field_16D8;
    int field_16DC;
    int field_16E0;
    int field_16E4;
    int field_16E8;
    int field_16EC;
    int field_16F0;
    int field_16F4;
    int field_16F8;
    int field_16FC;
    int field_1700;
    int field_1704;
    int field_1708;
    int field_170C;
    int field_1710;
    int field_1714;
    int field_1718;
    int field_171C;
    int field_1720;
    int field_1724;
    int field_1728;
    int field_172C;
    int field_1730;
    int field_1734;
    int field_1738;
    int field_173C;
    int field_1740;
    int field_1744;
    int field_1748;
    int field_174C;
    int field_1750;
    int field_1754;
    int field_1758;
    int field_175C;
    int field_1760;
    int field_1764;
    int field_1768;
    int field_176C;
    int field_1770;
    int field_1774;
    int field_1778;
    int field_177C;
    int field_1780;
    int field_1784;
    int field_1788;
    int field_178C;
    int field_1790;
    int field_1794;
    int field_1798;
    int field_179C;
    int field_17A0;
    int field_17A4;
    int field_17A8;
    int field_17AC;
    int field_17B0;
    int field_17B4;
    int field_17B8;
    int field_17BC;
    int field_17C0;
    int field_17C4;
    int field_17C8;
    int field_17CC;
    int field_17D0;
    int field_17D4;
    int field_17D8;
    int field_17DC;
    int field_17E0;
    int field_17E4;
    int field_17E8;
    int field_17EC;
    int field_17F0;
    int field_17F4;
    int field_17F8;
    int field_17FC;
    int field_1800;
    int field_1804;
    int field_1808;
    int field_180C;
    int field_1810;
    int field_1814;
    int field_1818;
    int field_181C;
    int field_1820;
    int field_1824;
    int field_1828;
    int field_182C;
    int field_1830;
    int field_1834;
    int field_1838;
    int field_183C;
    int field_1840;
    int field_1844;
    int field_1848;
    int field_184C;
    int field_1850;
    int field_1854;
    int field_1858;
    int field_185C;
    int field_1860;
    int field_1864;
    int field_1868;
    int field_186C;
    int field_1870;
    int field_1874;
    int field_1878;
    int field_187C;
    int field_1880;
    int field_1884;
    int field_1888;
    int field_188C;
    int field_1890;
    int field_1894;
    int field_1898;
    int field_189C;
    int field_18A0;
    int field_18A4;
    int field_18A8;
    int field_18AC;
    int field_18B0;
    int field_18B4;
    int field_18B8;
    int field_18BC;
    int field_18C0;
    int field_18C4;
    int field_18C8;
    int field_18CC;
    int field_18D0;
    int field_18D4;
    int field_18D8;
    int field_18DC;
    int field_18E0;
    int field_18E4;
    int field_18E8;
    int field_18EC;
    int field_18F0;
    int field_18F4;
    int field_18F8;
    int field_18FC;
    int field_1900;
    int field_1904;
    int field_1908;
    int field_190C;
    int field_1910;
    int field_1914;
    int field_1918;
    int field_191C;
    int field_1920;
    int field_1924;
    int field_1928;
    int field_192C;
    int field_1930;
    int field_1934;
    int field_1938;
    int field_193C;
    int field_1940;
    int field_1944;
    int field_1948;
    int field_194C;
    int field_1950;
    int field_1954;
    int field_1958;
    int field_195C;
    int field_1960;
    int field_1964;
    int field_1968;
    int field_196C;
    int field_1970;
    int field_1974;
    int field_1978;
    int field_197C;
    int field_1980;
    int field_1984;
    int field_1988;
    int field_198C;
    int field_1990;
    int field_1994;
    int field_1998;
    int field_199C;
    int field_19A0;
    int field_19A4;
    int field_19A8;
    int field_19AC;
    int field_19B0;
    int field_19B4;
    int field_19B8;
    int field_19BC;

    Em0310()
    {
        ((void(__thiscall *)(Em0310*))(shared::base + 0x6AD3E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735140);
};

class Em0310Weapon : public BehaviorWeapon
{
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;

    Em0310Weapon()
    {
        ((void(__thiscall *)(Em0310Weapon *))(shared::base + 0x6A6470))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735144);
};

class Em0310Pillar : public BehaviorBgBase
{
public:
    int field_A70;
    int field_A74;
    int field_A78;
    EntityHandle field_A7C;
    cEspControler field_A80;

    Em0310Pillar()
    {
        ((void(__thiscall *)(Em0310Pillar *))(shared::base + 0x6A64B0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735148);
};

class Em0310Shield : public Behavior
{
public:
    int field_870;
    EntityHandle field_874;
    int field_878;
    int field_87C;
    CollisionAttackData::AttackData m_AttackData;
    int field_980;
    float field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;

    Em0310Shield()
    {
        ((void(__thiscall *)(Em0310Shield *))(shared::base + 0x6A6370))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x173514C);
};

class Em0310QteObstacle : public BehaviorBgBase
{
public:
    cEspControler field_A70;
    CollisionAttackData::AttackData field_B20;
    int field_C20;
    int field_C24;
    int field_C28;
    int field_C2C;
    int field_C30;
    int field_C34;
    int field_C38;
    int field_C3C;
    
    Em0310QteObstacle()
    {
        ((void(__thiscall *)(Em0310QteObstacle*))(shared::base + 0x6A63D0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735150);
};

class Em0310QteCeiling : public BehaviorBgBase
{
public:
    CollisionAttackData::AttackData field_A70;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;

    Em0310QteCeiling()
    {
        ((void(__thiscall *)(Em0310QteCeiling*))(shared::base + 0x6A6410))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735154);
};

class Em0310QteCeilingDebris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    Em0310QteCeilingDebris()
    {
        ((void(__thiscall *)(Em0310QteCeilingDebris*))(shared::base + 0x6AFB70))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735158);
};

class Em0310QteDummy : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em0310QteDummy()
    {
        ((void(__thiscall *)(Em0310QteDummy *))(shared::base + 0x6A6440))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x173515C);
};

class Em0310Debris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    Em0310Debris()
    {
        ((void(__thiscall *)(Em0310Debris *))(shared::base + 0x6AFC00))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735160);
};

VALIDATE_SIZE(Em0310Shield, 0x9B0);
VALIDATE_SIZE(Em0310Weapon, 0x8D0);
VALIDATE_SIZE(Em0310QteObstacle, 0xC40);
VALIDATE_SIZE(Em0310QteDummy, 0x880);
VALIDATE_SIZE(Em0310Pillar, 0xB30);
VALIDATE_SIZE(Em0310QteCeilingDebris, 0x980);
VALIDATE_SIZE(Em0310QteCeiling, 0xB80);
VALIDATE_SIZE(Em0310Debris, 0x980);
VALIDATE_SIZE(Em0310, 0x19C0);