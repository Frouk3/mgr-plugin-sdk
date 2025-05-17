#pragma once
#include <cSlowRateUnit.h>
#include <SceneModelSystem.h>
#include <Hw.h>
#include <Animation.h>
#include <shared.h>
#include <eObjID.h>
#include <EntityHandle.h>
#include <HkDataManagerImplement.h>

struct EntitySystem;
class Behavior;

struct Entity
{
    cSlowRateUnit *m_pSlowRateUnit;
    char m_EntityName[32];
    eObjID m_EntityIndex;
    int m_EntityFlags;
    EntityHandle m_Handle;
    DataArchiveHolder m_EntityData;
    SceneModelSystem *m_pSceneManager;
    Behavior *m_pSceneModel;                 ///< There's no difference between m_SceneModel and m_Instance
    Animation *m_pAnimation;
    int field_44; // BehaviorInfo *
    Behavior *m_pInstance;
    BOOL m_bStartupImmediately; 
    int field_50;
    int field_54;
    int m_nSetType;
    int field_5C;

    struct ConstructInfo;

    BOOL construct(ConstructInfo* pConstructInfo)
    {
        return ((BOOL(__thiscall*)(Entity*, ConstructInfo*))(shared::base + 0x680E70))(this, pConstructInfo);
    }

    BOOL createAnimation()
    {
        return ((BOOL(__thiscall*)(Entity*))(shared::base + 0x67C810))(this);
    }

    template <typename T>
    T *getEntityInstance()
    {
        return ((T *(__thiscall*)(Entity*))(shared::base + 0x67C8A0))(this);
    }

    void updateDelta()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0xA049A0))(this);
    }

    float getDeltaTime()
    {
        return ((float(__thiscall*)(Entity*))(shared::base + 0xA049B0))(this);
    }

    BOOL setEntitySlowRateType(int SlowRateType)
    {
        return ((BOOL(__thiscall*)(Entity*, int))(shared::base + 0xA08640))(this, SlowRateType);
    }

    void setTransPos(const cVec4& transPos)
    {
        ((void(__thiscall*)(Entity*, const cVec4&))(shared::base + 0x67CE90))(this, transPos);
    }

    const cVec4& getTransPos()
    {
        return ((const cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8B0))(this);
    }

    void offsetTransPos(const cVec4& offset)
    {
        ((void(__thiscall*)(Entity*, const cVec4&))(shared::base + 0x67CEC0))(this, offset);
    }

    void setRotation(const cVec4& rotation)
    {
        ((void(__thiscall*)(Entity*, const cVec4&))(shared::base + 0x67CF00))(this, rotation);
    }

    const cVec4& getRotation()
    {
        return ((const cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8D0))(this);
    }

    void setSize(const cVec4& size)
    {
        ((void(__thiscall*)(Entity*, const cVec4&))(shared::base + 0x67CF90))(this, size);
    }

    const cVec4& getSize()
    {
        return ((const cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8F0))(this);
    }

    Animation* getAnimation()
    {
        return ((Animation * (__thiscall*)(Entity*))(shared::base + 0x67C890))(this);
    }

    BOOL isValid()
    {
        return ((BOOL(__thiscall*)(Entity*))(shared::base + 0x67C7E0))(this);
    }

    ~Entity()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0x6805F0))(this);
    }

    void shutdownAnimation()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0x67CE60))(this);
    }

    void shutdown()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0x681290))(this);
    }

    void shutdownSlowRateUnit()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0xA085E0))(this);
    }

    EntityHandle& getEntityHandle()
    {
        return ((EntityHandle & (__thiscall*)(Entity*))(shared::base + 0x67C7F0))(this);
    }
};

VALIDATE_SIZE(Entity, 0x60);