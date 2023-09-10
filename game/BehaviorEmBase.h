#pragma once
#include "BehaviorAppBase.h"
#include "cEnemyCautionStateManager.h"
#include "EntitySystem.h"

class BehaviorEmBase : public BehaviorAppBase
{
public:
    int field_9F4;
    int field_9F8;
    int field_9FC;
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    float field_A24;
    float field_A28;
    int field_A2C;
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    int field_A40;
    char field_A44;
    int field_A48;
    int field_A4C;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    Behavior* m_pEnemy;
    Entity *m_pEntityEnemy;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    EntitySystem::EntityInfo field_AB0;
    int field_BC8;
    int field_BCC;
    float field_BD0;
    int field_BD4;
    int field_BD8;
    int field_BDC;
    int field_BE0;
    int field_BE4;
    int field_BE8;
    int field_BEC;
    int field_BF0;
    float field_BF4;
    int field_BF8;
    int field_BFC;
    int field_C00;
    int field_C04;
    int field_C08;
    int field_C0C;
    cEnemyCautionStateManager field_C10;
    int field_D50;
    int field_D54;
    int field_D58;
    int field_D5C;
    int field_D60;
    int field_D64;
    int field_D68;
    int field_D6C;
    int field_D70;
    int field_D74;
    int field_D78;
    int field_D7C;
    int field_D80;
    int field_D84;
    int field_D88;
    float field_D8C;
    float field_D90;
    int field_D94;
    int field_D98;
    int field_D9C;
    int field_DA0;
    int field_DA4;
    int field_DA8;
    short field_DAC;
    int field_DB0;
    char field_DB4;

    void SetWait()
    {
        CallVMTFunc<211, BehaviorEmBase *>(this);
    }

    void CreateEffect(int effId, cEspControler *pEsp)
    {
        CallVMTFunc<214, BehaviorEmBase *, int, cEspControler *>(this, effId, pEsp);
    }
};