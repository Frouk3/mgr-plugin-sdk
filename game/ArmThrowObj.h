#pragma once

#include <BehaviorAppBase.h>

class ArmThrowObj : public BehaviorAppBase
{
public:
    EntityHandle field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    CollisionAttackData::HitData m_Attacks[8];
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
    cEspControler field_12E0;
    cEspControler field_1390;
    EntityHandle field_1440;
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
    EntityHandle field_1504[8];
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

    ArmThrowObj()
    {
        ((void(__thiscall *)(ArmThrowObj*))(shared::base + 0x6B3F20))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735AD8);
};

VALIDATE_SIZE(ArmThrowObj, 0x1550);