#pragma once

#include "cObj.h"
#include "hkpRigidBody.h"
#include "cLockonPartsList.h"
#include "BattleParameterImplement.h"
#include "EspCtrlCustomImpl.h"
#include "CharacterControl.h"
#include "lib.h"
#include "StateMachineContextPl0010.h"
#include "StateMachineFactoryPl0010.h"
#include <D3dx9math.h>

struct Constraints
{
    eObjID m_nIndex;
    int field_4;
    EntityHandle m_nObjectEntityHandle;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    cVec4 m_vecOffset;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};

class Behavior : public cObj
{
public:
    struct AnimationSlot
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
        float field_28;
        int field_2C;
    };

    struct EffectIntegrationContainer
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
    };

    int field_530;
    int field_534;
    int field_538;
    int field_53C;
    cVec4 field_540;
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
    float field_560;
    float field_564;
    float field_568;
    float field_56C;
    int field_570;
    int field_574;
    int field_578;
    int field_57C;
    int field_580;
    int field_584;
    int *field_588;
    int field_58C;
    char field_590;
    int field_594;
    int field_598;
    int field_59C;
    int field_5A0;
    int field_5A4;
    int field_5A8;
    int field_5AC;
    int field_5B0;
    int field_5B4;
    int field_5B8;
    int field_5BC;
    int field_5C0;
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4;
    int field_5D8;
    int field_5DC;
    int field_5E0;
    int field_5E4;
    int field_5E8;
    int field_5EC;
    hkpRigidBody *field_5F0;
    hkpRigidBody *field_5F4;
    int field_5F8;
    int field_5FC;
    float field_600;
    int field_604;
    int field_608;
    void* m_pBehaviorInfo;
    int field_610;
    int field_614;
    unsigned int m_nCurrentAction;
    int m_nCurrentActionId;
    int field_620;
    int field_624;
    unsigned int m_nPreviousAction;
    int m_nPreviousActionId;
    int field_630;
    int field_634;
    int field_638;
    int field_63C;
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
    int field_654;
    int field_658;
    int field_65C;
    int field_660;
    int field_664;
    int field_668;
    int field_66C;
    int field_670;
    int field_674;
    int field_678;
    int field_67C;
    int field_680;
    int field_684;
    int field_688;
    int field_68C;
    int field_690;
    float field_694;
    float field_698;
    float field_69C;
    float field_6A0;
    float field_6A4;
    float field_6A8;
    float field_6AC;
    char field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    float field_6D0;
    float field_6D4;
    float field_6D8;
    float field_6DC;
    int field_6E0;
    int field_6E4;
    float field_6E8;
    int field_6EC;
    cLockonPartsList m_cLockonPartsList;
    int field_710;
    int field_714;
    int field_718;
    int field_71C;
    int field_720;
    int field_724;
    int field_728;
    int field_72C;
    int field_730;
    int field_734;
    float field_738;
    int field_73C;
    int field_740;
    int field_744;
    int field_748;
    int field_74C;
    int field_750;
    BattleParameterImplement *m_pBattleParameterImplement;
    int field_758;
    int field_75C;
    int field_760;
    CharacterControl *m_pCharacterControl;
    int field_768;
    int field_76C;
    int field_770;
    lib::StaticArray<AnimationSlot, 16> *m_pAnimationSlots;
    int field_778;
    int field_77C;
    int field_780;
    float field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    EspCtrlCustomImpl *m_pEspCtrlCustomImpl;
    int field_79C;
    lib::StaticArray<EffectIntegrationContainer, 32> *m_pEffectIntegrationContainer;
    int field_7A4;
    int field_7A8;
    int field_7AC;
    int field_7B0;
    int field_7B4;
    int field_7B8;
    int field_7BC;
    float field_7C0;
    lib::StaticArray<Constraints, 32> **m_pContraints;
    int field_7C8;
    int field_7CC;
    StateMachineContextPl0010 *m_pStateMachineContext;
    StateMachineFactoryPl0010 *m_pStateMachineFactory;
    int field_7D8;
    int field_7DC;
    int field_7E0;
    int field_7E4;
    int field_7E8;
    int field_7EC;
    int field_7F0;
    int field_7F4;
    int field_7F8;
    int field_7FC;
    int field_800;
    int field_804;
    int field_808;
    int field_80C;
    int field_810;
    int field_814;
    int field_818;
    int field_81C;
    int field_820;
    short field_824;
    int field_828;
    int field_82C;
    int field_830;
    int field_834;
    int field_838;
    int field_83C;
    int field_840;
    int field_844;
    char field_848;
    char field_849;
    int field_84C;
    int field_850;
    int field_854;
    int field_858;
    int field_85C;
    float field_860;
    float field_864;
    float field_868;
    float field_86C;

    Behavior()
    {
        ((void(__thiscall *)(Behavior *))(shared::base + 0x6A3540))(this);
    }

// vft

    BOOL startup()
    {
        return ReturnCallVMTFunc<BOOL, 16, Behavior *>(this);
    }
    BOOL shutdown()
    {
        return ReturnCallVMTFunc<BOOL, 17, Behavior *>(this);
    }
    void tick()
    {
        CallVMTFunc<19, Behavior *>(this);
    }
    void updateBodyParts()
    {
        CallVMTFunc<21, Behavior *>(this);
    }
    cVec4 *getTransPos()
    {
        return ReturnCallVMTFunc<cVec4 *, 26, Behavior *>(this);
    }
    void setTransPos(cVec4 *transPos)
    {
        CallVMTFunc<27, Behavior *, cVec4 *>(this, transPos);
    }
    void offsetTransPos(cVec4 *offset)
    {
        CallVMTFunc<28, Behavior *, cVec4 *>(this, offset);
    }
    void changeHeight(float height)
    {
        CallVMTFunc<29, Behavior *, float>(this, height);
    }
    void place(cVec4 *pos, cVec4* rotation, cVec4 *size)
    {
        CallVMTFunc<30, Behavior *, cVec4 *, cVec4 *, cVec4 *>(this, pos, rotation, size);
    }
    void place(cVec4 *pos, cVec4* rotation)
    {
        CallVMTFunc<31, Behavior *, cVec4 *, cVec4 *>(this, pos, rotation);
    }
    cVec4 *getRotation()
    {
        return ReturnCallVMTFunc<cVec4 *, 33, Behavior *>(this);
    }
    void setRotation(cVec4 *rotation)
    {
        CallVMTFunc<34, Behavior *, cVec4 *>(this, rotation);
    }
    cVec4 *getSize()
    {
        return ReturnCallVMTFunc<cVec4 *, 35, Behavior *>(this);
    }
    void setSize(cVec4 *size)
    {
        CallVMTFunc<36, Behavior *, cVec4 *>(this, size);
    }
    int getSequence()
    {
        return ReturnCallVMTFunc<int, 37, Behavior *>(this);
    }
    int getIndex()
    {
        return ReturnCallVMTFunc<int, 38, Behavior *>(this);
    }
    int getSequenceFile(const char *a2)
    {
        return ReturnCallVMTFunc<int, 39, Behavior *, const char*>(this, a2);
    }
    void transform(D3DXMATRIX *matrix)
    {
        CallVMTFunc<45, Behavior *, D3DXMATRIX *>(this, matrix);
    }
    void inverse(D3DXMATRIX *matrix)
    {
        CallVMTFunc<46, Behavior *, D3DXMATRIX *>(this, matrix);
    }
    void setStealthCamoEnabled(bool bEnable)
    {
        CallVMTFunc<68, Behavior *, bool>(this, bEnable);
    }
    void setSeqAtk()
    {
        CallVMTFunc<74, Behavior *>(this);
    }
    void *setCutCreateInfo()
    {
        return ReturnCallVMTFunc<void *, 110, Behavior *>(this);
    }
    bool isAlive()
    {
        return ReturnCallVMTFunc<bool, 128, Behavior *>(this);
    }
    cVec4 getOffsetPosition()
    {
        return ReturnCallVMTFunc<cVec4, 159, Behavior *>(this);
    }

// vft end

    void setState(int action, int actId, int a3, int a4)
    {
        ((void (__thiscall *)(Behavior *, int, int, int, int))(shared::base + 0x68CAF0))(this, action, actId, a3, a4);
    }
    int getCurrentActionId()
    {
        return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAC0))(this);
    }
    int getCurrentAction()
    {
        return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAB0))(this);
    }
    bool setupCloth(int a2)
    {
        return ((bool (__thiscall *)(Behavior *, int))(shared::base + 0x692380))(this, a2);
    }

    int requestAnimationByMap(int animId, Entity *pAnimEntity, int a4, float a5, float a6, unsigned int animFlags, float a8, float a9)
    {
        return ((int (__thiscall *)(Behavior *, int, Entity *, int, float, float, unsigned int, float, float))(shared::base + 0x6A4520))(this, animId, pAnimEntity, a4, a5, a6, animFlags, a8, a9);
    }

    int requestAnimationByMap(Entity *pAnimEntity, int a2, int a3, int a4, int a5, int a6, const char* motId, float a9, unsigned int flags)
    {
        return ((int (__thiscall *)(Behavior *, Entity *, int, int, int, int, int, const char*, float, unsigned int))(shared::base + 0x694850))(this, pAnimEntity, a2, a3, a4, a5, a6, motId, a9, flags);
    }

    void removeConstraint(int constraintId)
    {
        ((void (__thiscall *)(Behavior*, int))(shared::base + 0x69E060))(this, constraintId);
    }
};

struct BehaviorData
{

};

VALIDATE_SIZE(Behavior, 0x870);