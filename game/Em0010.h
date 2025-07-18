#pragma once

#include <BehaviorEmBase.h>
#include <Slot.h>
#include <hkpPhantomOverlapListener.h>
#include <BehaviorPartsModel.h>
#include <BehaviorWeapon.h>
#include <BehaviorBgBase.h>

class Em0010DebrisTest : public BehaviorBgBase
{
public:
    int field_A70;
    EntityHandle field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;
    cEspControler field_A90;

    Em0010DebrisTest()
    {
        ((void(__thiscall *)(Em0010DebrisTest*))(shared::base + 0x1E4DE0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735364);
};

class cEm0010Weapon : public BehaviorWeapon
{
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    EntityHandle field_8CC;

    cEm0010Weapon()
    {
        ((void(__thiscall *)(cEm0010Weapon *))(shared::base + 0x6A6830))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D28);
};

class cEm0010Magazine : public BehaviorPartsModel
{
public:
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    EntityHandle field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;

    cEm0010Magazine()
    {
        ((void(__thiscall *)(cEm0010Magazine*))(shared::base + 0x6AF110))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D24);
};

class EmC010Weapon : public cEm0010Weapon
{
public:
    
    EmC010Weapon()
    {
        ((void(__thiscall *)(EmC010Weapon *))(shared::base + 0x6B4090))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17357A8);
};

class Em0010WeaponShield : public cEm0010Weapon
{
public:
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;

    Em0010WeaponShield()
    {
        ((void(__thiscall *)(Em0010WeaponShield *))(shared::base + 0x6AF1C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D2C);
};

class Em0010RPGBullet : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em0010RPGBullet()
    {
        ((void(__thiscall *)(Em0010RPGBullet *))(shared::base + 0x6A68D0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9D30);
};

class Em0010DebrisActor : public Behavior
{
public:
    class DebrisPhantomListener : public hkpPhantomOverlapListener{};
    class ExplosionSlot : public Slot
    {
    public:
        class Em0010 *m_Owner;
    };
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
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;

    Em0010DebrisActor()
    {
        ((void(__thiscall *)(Em0010DebrisActor*))(shared::base + 0x6A6BA0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735360);
};

class Em0010 : public BehaviorEmBase
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
    cEspControler field_DE0;
    cEspControler field_E90;
    float field_F40;
    EntityHandle field_F44;
    EntityHandle field_F48;
    int field_F4C;
    EntityHandle field_F50;
    EntityHandle field_F54;
    EntityHandle field_F58;
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
    cEspControler field_FD0;
    int field_1080;
    int field_1084;
    int field_1088;
    int field_108C;
    int field_1090;
    EntityHandle field_1094;
    EntityHandle field_1098;
    EntityHandle field_109C;
    EntityHandle field_10A0;
    EntityHandle field_10A4;
    EntityHandle field_10A8;
    EntityHandle field_10AC;
    EntityHandle field_10B0;
    EntityHandle field_10B4;
    EntityHandle field_10B8;
    EntityHandle field_10BC;
    cEspControler field_10C0;
    cEspControler field_1170;
    cEspControler field_1220;
    int field_12D0;
    int field_12D4;
    int field_12D8;
    int field_12DC;
    int field_12E0;
    int field_12E4;
    int field_12E8;
    int field_12EC;
    cEspControler field_12F0;
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
    float field_15BC;
    int field_15C0;
    int field_15C4;
    int field_15C8;
    int field_15CC;
    cEspControler field_15D0;
    EntityHandle field_1680;
    EntityHandle field_1684;
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
    cEspControler field_1770;
    int field_1820;
    int field_1824;
    int field_1828;
    int field_182C;
    cEspControler field_1830;
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
    float field_1974;
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
    int field_19C0;
    int field_19C4;
    int field_19C8;
    int field_19CC;
    int field_19D0;
    int field_19D4;
    EntityHandle field_19D8;
    int field_19DC;
    int field_19E0;
    int field_19E4;
    int field_19E8;
    int field_19EC;
    int field_19F0;
    int field_19F4;
    int field_19F8;
    int field_19FC;
    int field_1A00;
    int field_1A04;
    int field_1A08;
    int field_1A0C;
    int field_1A10;
    int field_1A14;
    int field_1A18;
    int field_1A1C;
    int field_1A20;
    int field_1A24;
    int field_1A28;
    int field_1A2C;
    int field_1A30;
    int field_1A34;
    int field_1A38;
    int field_1A3C;
    int field_1A40;
    int field_1A44;
    int field_1A48;
    int field_1A4C;
    int field_1A50;
    int field_1A54;
    int field_1A58;
    int field_1A5C;
    int field_1A60;
    int field_1A64;
    int field_1A68;
    int field_1A6C;
    int field_1A70;
    int field_1A74;
    int field_1A78;
    int field_1A7C;
    int field_1A80;
    int field_1A84;
    int field_1A88;
    int field_1A8C;
    int field_1A90;
    int field_1A94;
    int field_1A98;
    int field_1A9C;
    int field_1AA0;
    int field_1AA4;
    int field_1AA8;
    int field_1AAC;
    int field_1AB0;
    int field_1AB4;
    int field_1AB8;
    int field_1ABC;
    int field_1AC0;
    int field_1AC4;
    int field_1AC8;
    int field_1ACC;
    int field_1AD0;
    int field_1AD4;
    int field_1AD8;
    int field_1ADC;
    int field_1AE0;
    int field_1AE4;
    int field_1AE8;
    int field_1AEC;
    int field_1AF0;
    int field_1AF4;
    int field_1AF8;
    int field_1AFC;
    int field_1B00;
    int field_1B04;
    int field_1B08;
    int field_1B0C;
    int field_1B10;
    int field_1B14;
    int field_1B18;
    int field_1B1C;
    int field_1B20;
    int field_1B24;
    int field_1B28;
    int field_1B2C;
    int field_1B30;
    int field_1B34;
    int field_1B38;
    int field_1B3C;
    int field_1B40;
    int field_1B44;
    int field_1B48;
    int field_1B4C;
    int field_1B50;
    int field_1B54;
    int field_1B58;
    int field_1B5C;
    int field_1B60;
    int field_1B64;
    int field_1B68;
    int field_1B6C;

    Em0010()
    {
        ((void(__thiscall *)(Em0010 *))(shared::base + 0x6AB940))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D20);
};

VALIDATE_SIZE(Em0010DebrisTest, 0xB40);
VALIDATE_SIZE(cEm0010Weapon, 0x8D0);
VALIDATE_SIZE(cEm0010Magazine, 0xA80);
VALIDATE_SIZE(EmC010Weapon, 0x8D0);
VALIDATE_SIZE(Em0010WeaponShield, 0x8E0);
VALIDATE_SIZE(Em0010RPGBullet, 0x880);
VALIDATE_SIZE(Em0010DebrisActor, 0x910);
VALIDATE_SIZE(Em0010, 0x1B70);