#pragma once

#include <BehaviorEmBase.h>

class MonYoyoObj : public BehaviorEmBase
{
public:
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;
    CollisionAttackData::AttackData field_DD0[8];
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
    cEspControler field_16A0;
    cEspControler field_1750;
    int EntityHandle;
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

    MonYoyoObj()
    {
        ((void(__thiscall *)(MonYoyoObj*))(shared::base + 0x6B11E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734F68);
};

VALIDATE_SIZE(MonYoyoObj, 0x18E0);