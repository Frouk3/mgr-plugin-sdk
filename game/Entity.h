#pragma once
#include <SceneModelSystem.h>
#include <Hw.h>
#include <Animation.h>
#include <shared.h>
#include <eObjID.h>
#include <EntityHandle.h>
#include <HkDataManagerImplement.h>
#include <SceneBehaviorSystem.h>
#include <cSlowRateManager.h>

struct EntitySystem;
class Behavior;

class Entity
{
public:
    cSlowRate m_SlowRate;
    char m_pName[32];
    eObjID m_ObjId;
    int m_Flags;
    EntityHandle m_Handle;
    Hw::cFmerge m_EntityData;
    SceneModelSystem *m_pSceneManager;
    Behavior *m_pSceneModel;                 ///< There's no difference between m_pSceneModel and m_pInstance
    Animation *m_pAnimation;
    BehaviorList *m_pBehaviorList;
    Behavior *m_pInstance;
    BOOL m_bStartupImmediately; 
    BOOL m_bDebris;
    BOOL m_bDatsuEntity;
    int m_SetType;
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

    void setTransPos(const Hw::cVec4& transPos)
    {
        ((void(__thiscall*)(Entity*, const Hw::cVec4&))(shared::base + 0x67CE90))(this, transPos);
    }

    const Hw::cVec4& getTransPos()
    {
        return ((const Hw::cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8B0))(this);
    }

    void offsetTransPos(const Hw::cVec4& offset)
    {
        ((void(__thiscall*)(Entity*, const Hw::cVec4&))(shared::base + 0x67CEC0))(this, offset);
    }

    void setRotation(const Hw::cVec4& rotation)
    {
        ((void(__thiscall*)(Entity*, const Hw::cVec4&))(shared::base + 0x67CF00))(this, rotation);
    }

    const Hw::cVec4& getRotation()
    {
        return ((const Hw::cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8D0))(this);
    }

    void setSize(const Hw::cVec4& size)
    {
        ((void(__thiscall*)(Entity*, const Hw::cVec4&))(shared::base + 0x67CF90))(this, size);
    }

    const Hw::cVec4& getSize()
    {
        return ((const Hw::cVec4&(__thiscall*)(Entity*))(shared::base + 0x67C8F0))(this);
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