#pragma once
#include "cSlowRateUnit.h"
#include "SceneModelSystem.h"
#include "cVec4.h"
#include "Hw.h"
#include "Animation.h"
#include "shared.h"
#include "eObjID.h"
#include "EntityHandle.h"

struct EntitySystem;

struct Entity
{
    cSlowRateUnit* m_pSlowRateUnit;
    char m_EntityName[16];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    eObjID m_nEntityIndex;
    unsigned int m_nEntityFlags;
    EntityHandle m_nEntityHandle;
    int field_30;
    int field_34;
    SceneModelSystem* m_pSceneModelSystem;
    void* m_pSpecifiedInstance;
    Animation* m_pAnimation;
    int field_44;
    void* m_pInstance;
    BOOL m_bModelRegistered;
    int field_50;
    int field_54;
    int m_nSetType;
    int field_5C;

    struct ConstructInfo;

    BOOL construct(ConstructInfo* pConstructInfo)
    {
        return ((BOOL(__thiscall*)(Entity*, ConstructInfo*))(shared::base + 0x680E70))(this, pConstructInfo);
    }
    void* getEntityInstance()
    {
        return ((void* (__thiscall*)(Entity*))(shared::base + 0x67C8A0))(this);
    }
    void updateSlowRateUnit()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0xA049A0))(this);
    }
    float getCalculatedSlowRate()
    {
        return ((float(__thiscall*)(Entity*))(shared::base + 0xA049B0))(this);
    }
    void setEntitySlowRateType(int SlowRateType)
    {
        ((void(__thiscall*)(Entity*, int))(shared::base + 0xA08640))(this, SlowRateType);
    }
    void setTransPos(cVec4* transPos)
    {
        ((void(__thiscall*)(Entity*, cVec4*))(shared::base + 0x67CE90))(this, transPos);
    }
    cVec4* getTransPos()
    {
        return ((cVec4 * (__thiscall*)(Entity*))(shared::base + 0x67C8B0))(this);
    }
    void offsetTransPos(cVec4* offset)
    {
        ((void(__thiscall*)(Entity*, cVec4*))(shared::base + 0x67CEC0))(this, offset);
    }
    void setRotation(cVec4* rotation)
    {
        ((void(__thiscall*)(Entity*, cVec4*))(shared::base + 0x67CF00))(this, rotation);
    }
    cVec4* getRotation()
    {
        return ((cVec4 * (__thiscall*)(Entity*))(shared::base + 0x67C8D0))(this);
    }
    void setSize(cVec4* size)
    {
        ((void(__thiscall*)(Entity*, cVec4*))(shared::base + 0x67CF90))(this, size);
    }
    cVec4* getSize()
    {
        return ((cVec4 * (__thiscall*)(Entity*))(shared::base + 0x67C8F0))(this);
    }
    ~Entity()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0x6805F0))(this);
    }
    void shutdownInstance()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0x681290))(this);
    }
    void shutdownSlowRateUnit()
    {
        ((void(__thiscall*)(Entity*))(shared::base + 0xA085E0))(this);
    }
    EntityHandle *getEntityHandle()
    {
        return ((EntityHandle *(__thiscall *)(Entity *))(shared::base + 0x67C7F0))(this);
    } 
};

VALIDATE_SIZE(Entity, 0x60);