#pragma once

#include <BehaviorBa.h>
#include <BehaviorAppBase.h>

class BaContainer : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    BaContainer()
    {
        ((void(__thiscall *)(BaContainer*))(shared::base + 0x6B0F40))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734D74);
};

class BaContainerParts : public BehaviorAppBase
{
public:
    CollisionAttackData::HitData field_A00[8];
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
    cEspControler field_12D0;
    cEspControler field_1380;
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

    BaContainerParts()
    {
        ((void(__thiscall *)(BaContainerParts *))(shared::base + 0x6B0F90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734D78);
};

VALIDATE_SIZE(BaContainerParts, 0x1490);
VALIDATE_SIZE(BaContainer, 0xB40);