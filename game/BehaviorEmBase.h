#pragma once
#include <BehaviorAppBase.h>
#include <cEnemyCautionStateManager.h>
#include <EntitySystem.h>

class BehaviorEmBase : public BehaviorAppBase
{
public:
    Hw::CriticalSection field_A00;
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
    EntityHandle m_BodyHandle;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    int field_A60;
    DataArchiveHolder field_A64;
    DataArchiveHolder field_A6C;
    DataArchiveHolder field_A74;
    int field_A7C;
    int field_A80;
    Pl0000 *m_pEnemy;
    Entity *m_pEnemyEntity;
    float m_fDistance;
    float m_fDistance2D; // X && Z distance
    float field_A94;
    float field_A98;
    float m_fAngleToEnemy;
    float field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    EntitySystem::SetInfo m_SetInfo;
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
    cEnemyCautionStateManager m_CautionStateManager;
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
    short field_DAE;
    int field_DB0;
    char field_DB4;
    int field_DB8;
    int field_DBC;

    BehaviorEmBase()
    {
        ((void(__thiscall *)(BehaviorEmBase *))(shared::base + 0xED790))(this);
    }

    void setWait()
    {
        CallVMTFunc<211, BehaviorEmBase *>(this);
    }

    void createEffect(int effId, cEspControler *pEsp)
    {
        CallVMTFunc<214, BehaviorEmBase *, int, cEspControler *>(this, effId, pEsp);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C78);
};

VALIDATE_SIZE(BehaviorEmBase, 0xDC0);