#pragma once

#include <BehaviorAppBase.h>

class MonQteObj : public BehaviorAppBase
{
public:
    CollisionAttackData::HitData m_ObjAttackData[8];
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
    cEspControler field_1230;
    int field_12E0;
    int field_12E4;
    int field_12E8;
    int field_12EC;
    int field_12F0;
    int field_12F4;
    int field_12F8;
    int field_12FC;

    MonQteObj()
    {
        MAKE_CALL(shared::base + 0x6AECC0, void(__thiscall *)(MonQteObj *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734F60);
};

VALIDATE_SIZE(MonQteObj, 0x1300);