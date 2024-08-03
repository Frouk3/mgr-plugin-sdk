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
#include <AnimationMapManagerImplement.h>
#include "Collision.h"
#include "RigidBodyCollision.h"

struct Constraints
{
    int m_nIndex;
    EntityHandle m_nMainEntity;
    EntityHandle m_nObjectEntityHandle;
    unsigned int m_nBone;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    Hw::cVec4 m_vecRotation;
    Hw::cVec4 m_vecOffset;
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
        char m_AnimName[16];
        Behavior* m_Parent;
        int field_1C;
        AnimationMap::Unit* m_AnimationMap;
        int field_24;
        float m_fAnimTimer;
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

    struct InstructionContainer
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
        int field_28;
        int field_2C;
        int field_30;
    };

    int field_530;
    int field_534;
    int field_538;
    int field_53C;
    Hw::cVec4 field_540;
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
    float field_560;
    float field_564;
    float field_568;
    float field_56C;
    float field_570;
    float field_574;
    float field_578;
    float field_57C;
    float field_580;
    float field_584;
    float field_588;
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
    int m_pBehaviorInfo;
    int field_610;
    int field_614;
    unsigned int m_nCurrentAction;
    int m_nCurrentActionId;
    int field_620;
    int field_624;
    int m_nPreviousAction;
    int m_nPreviousActionId;
    int field_630;
    int field_634;
    int field_638;
    lib::AllocatedArray<InstructionContainer> *m_pInstructionContainerArray;
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
    EntityHandle field_66C;
    int field_670;
    int field_674;
    Hw::cFixedVector<int> field_678; // FIXME LATER;;
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
    lib::AllocatedArray<AnimationMap::Unit> **m_ppAnimationMap;
    int field_760;
    CharacterControl *m_pCharacterControl;
    int field_768;
    int field_76C;
    int field_770;
    lib::StaticArray<AnimationSlot, 16> *m_pAnimationSlot;
    int field_778;
    int field_77C;
    int field_780;
    float field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    EspCtrlCustomImpl *m_pEspCtrlCustomImpl;
    cEspControler *field_79C;
    lib::StaticArray<EffectIntegrationContainer, 32> *m_pEffectIntegrationContainer;
    lib::StaticArray<Collision *, 250> *m_pAttackCollision;
    lib::StaticArray<Collision *, 64> *m_pDefenseCollisions;
    int field_7AC;
    RigidBodyCollision *m_pRigidBodyCollision;
    void *m_pRigidBodyList;
    lib::AllocatedArray<Collision*> *m_pAllocatedCollisionArray;
    int field_7BC;
    float field_7C0;
    lib::StaticArray<Constraints, 32> **m_ppConstraints;
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
    int field_824;
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

    void updateLogic()
    {
        CallVMTFunc<18, Behavior*>(this);
    }

    void tick()
    {
        CallVMTFunc<19, Behavior *>(this);
    }

    void updateModel()
    {
        CallVMTFunc<20, Behavior *>(this);
    }
    
    void updateEntity()
    {
        CallVMTFunc<21, Behavior*>(this);
    }

    Hw::cVec4 *getTransPos()
    {
        return ReturnCallVMTFunc<Hw::cVec4 *, 26, Behavior *>(this);
    }

    void setTransPos(const Hw::cVec4& transPos)
    {
        CallVMTFunc<27, Behavior *, const Hw::cVec4&>(this, transPos);
    }

    void offsetTransPos(const Hw::cVec4& offset)
    {
        CallVMTFunc<28, Behavior *, const Hw::cVec4&>(this, offset);
    }

    void changeHeight(const float height)
    {
        CallVMTFunc<29, Behavior *, float>(this, height);
    }

    void place(const Hw::cVec4 &pos, const Hw::cVec4& rotation, const Hw::cVec4& size)
    {
        CallVMTFunc<30, Behavior *, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&>(this, pos, rotation, size);
    }

    void place(const Hw::cVec4 &pos, const Hw::cVec4 &rotation)
    {
        CallVMTFunc<31, Behavior *, const Hw::cVec4&, const Hw::cVec4&>(this, pos, rotation);
    }

    Hw::cVec4* getRotation()
    {
        return ReturnCallVMTFunc<Hw::cVec4*, 33, Behavior *>(this);
    }

    void setRotation(const Hw::cVec4& rotation)
    {
        CallVMTFunc<34, Behavior *, const Hw::cVec4&>(this, rotation);
    }

    Hw::cVec4* getSize()
    {
        return ReturnCallVMTFunc<Hw::cVec4*, 35, Behavior *>(this);
    }

    void setSize(const Hw::cVec4& size)
    {
        CallVMTFunc<36, Behavior *, const Hw::cVec4&>(this, size);
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

    Hw::cVec4 getOffsetPosition()
    {
        return ReturnCallVMTFunc<Hw::cVec4, 159, Behavior *>(this);
    }

    void forceDie()
    {
        CallVMTFunc<190, Behavior*>(this);
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

    int requestAnimationByMap(int animId, Entity* pEntityFrom, int a4, float fInterpolation, float a6, unsigned int nFlags, float fStartFrame, float a9)
    {
        return ((int (__thiscall *)(Behavior *, int, Entity *, int, float, float, unsigned int, float, float))(shared::base + 0x6A4520))(this, animId, pEntityFrom, a4, fInterpolation, a6, nFlags, fStartFrame, a9);
    }

    int requestAnimationByMap(Entity *pAnimEntity, int a2, int a3, int a4, int a5, int a6, const char* motId, float a9, unsigned int nFlags)
    {
        return ((int (__thiscall *)(Behavior *, Entity *, int, int, int, int, int, const char*, float, unsigned int))(shared::base + 0x694850))(this, pAnimEntity, a2, a3, a4, a5, a6, motId, a9, nFlags);
    }

    void removeConstraint(int constraintId)
    {
        ((void (__thiscall *)(Behavior*, int))(shared::base + 0x69E060))(this, constraintId);
    }

    void attachObject(int constrId, Entity* entityAttachTo, Entity* attachedEntity, int bone, int _bone)
    {
        ((void(__thiscall*)(Behavior*, int, Entity*, Entity*, int, int))(shared::base + 0x68C5F0))(this, constrId, entityAttachTo, attachedEntity, bone, _bone);
    }

    void shutdownBattleParameter()
    {
        ((void(__thiscall*)(Behavior*))(shared::base + 0x692A00))(this);
    }

    Animation* getAnimation()
    {
        return ((Animation * (__thiscall*)(Behavior*))(shared::base + 0x692F90))(this);
    }

    float getSpeedRate()
    {
        return ((float(__thiscall*)(Behavior*))(shared::base + 0x692FF0))(this);
    }

    float getDelta()
    {
        return ((float(__thiscall*)(Behavior*))(shared::base + 0x693060))(this);
    }

    Constraints* getConstraints(int id)
    {
        return ((Constraints * (__thiscall*)(Behavior*, int))(shared::base + 0x6943E0))(this, id);
    }

    Entity* getConstraintsEntity(int id)
    {
        return ((Entity * (__thiscall*)(Behavior*, int))(shared::base + 0x694480))(this, id);
    }

    void shutdownConstraints()
    {
        ((void(__thiscall*)(Behavior*))(shared::base + 0x6944D0))(this);
    }

    void setConstraintsBone(int id, unsigned int bone, unsigned int _bone)
    {
        ((void(__thiscall*)(Behavior*, int, unsigned int, unsigned int))(shared::base + 0x69E120))(this, id, bone, _bone);
    }

    int setDirectAnimation(void* mot, void* seq, int a4, float fInterpolation, float a6, unsigned int nFlags, float fStartFrame, float a9)
    {
       return ((int(__thiscall*)(Behavior*, void*, void*, int, float, float, unsigned int, float, float))(shared::base + 0x69EFB0))(this, mot, seq, a4, fInterpolation, a6, nFlags, fStartFrame, a9);
    }

    // Takes all values from the animation map and plays the animation
    int requestAnimationByMap(int id)
    {
        return ((int(__thiscall*)(Behavior*, int))(shared::base + 0x6A3F60))(this, id);
    }
    
    // Unlike others, motion file is taken from the data file of this object
    int rqeuestAnimationByName(const char* anim, int a3, float fInterpolation, int a5, unsigned int nFlags, float fStartFrame, float a8)
    {
        return ((int(__thiscall*)(Behavior*, const char*, int, float, int, unsigned int, float, float))(shared::base + 0x69E290))(this, anim, a3, fInterpolation, a5, nFlags, fStartFrame, a8);
    }

    static inline ContextInstance &Context = *(ContextInstance*)(shared::base + 0x17E9C20);
};

struct BehaviorData
{

};

VALIDATE_SIZE(Behavior::AnimationSlot, 0x30);
VALIDATE_SIZE(Behavior, 0x870);