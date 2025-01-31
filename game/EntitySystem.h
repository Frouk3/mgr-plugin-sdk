#pragma once

#include <Hw.h>
#include <SceneModelSystem.h>
#include <Entity.h>
#include <Behavior.h>
#include <EntityHandle.h>
#include <common.h>

struct EntitySystem
{
    size_t m_nEntityCapacity; // how much entities can we hold?
    Hw::cHeapVariable* m_pHeapVariable;
    SceneModelSystem* m_pSceneModelSystem;
    int field_C;
    int field_10;
    int field_14;
    Hw::CriticalSection m_EntityListSection;
    int field_34;
    Hw::cFixedList<Entity *> m_EntityList;
    int field_54;
    int field_58;
    int field_5C;
    Hw::cHeapFixed m_HeapFixed;
    Hw::CriticalSection m_EntitySpawnSection;
    int field_DC;
    lib::AllocatedArray<Entity *> field_E0;
    lib::AllocatedArray<Entity *> m_DatsuArray;
    Hw::CriticalSection field_110;

    struct SetInfo;
    struct EntityInfo;
    struct ObjectInfo;

    Entity* createEntity(const char* name, eObjID objID, ObjectInfo* pObjInfo)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, const char*, eObjID, ObjectInfo*))(shared::base + 0x682090))(this, name, objID, pObjInfo);
    }
    Entity* createEntity(EntityInfo* pInfo)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, EntityInfo*))(shared::base + 0x681B80))(this, pInfo);
    }

    Entity* findEntity(eObjID objID)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, eObjID))(shared::base + 0x67F600))(this, objID);
    }

    BOOL addDatsuEntity(Entity* datsuEnt)
    {
        return ((BOOL(__thiscall*)(EntitySystem*, Entity*))(shared::base + 0x67F3B0))(this, datsuEnt);
    }

    void getEntities(eObjID id, lib::Array<Entity*>* pArray)
    {
        ((void(__thiscall*)(EntitySystem*, eObjID, lib::Array<Entity*>*))(shared::base + 0x67F440))(this, id, pArray);
    }

    void getEntities(eObjID id, lib::Array<EntityHandle>* pArray)
    {
        ((void(__thiscall*)(EntitySystem*, eObjID, lib::Array<EntityHandle>*))(shared::base + 0x67F4A0))(this, id, pArray);
    }

    void getEntities(eObjID objId, unsigned int hashNo, lib::Array<EntityHandle>* pArray)
    {
        ((void(__thiscall*)(EntitySystem*, eObjID, unsigned int, lib::Array<EntityHandle> *))(shared::base + 0x67F520))(this, objId, hashNo, pArray);
    }

    size_t getAmountOfEntitesByObjId(eObjID objId)
    {
        return ((size_t(__thiscall*)(EntitySystem*, eObjID))(shared::base + 0x67F5B0))(this, objId);
    }

    Entity* getClosestEntity(eObjID objId, const cVec4& position, const float distance)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, eObjID, const cVec4&, const float))(shared::base + 0x67F660))(this, objId, position, distance);
    }

    Entity* findEntity(const char* name, eObjID objId)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, const char*, eObjID))(shared::base + 0x67F710))(this, name, objId);
    }

    Entity* getClosestEntity(eObjID objId, const cVec4& position)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, eObjID, const cVec4&))(shared::base + 0x67F7B0))(this, objId, position);
    }

    size_t getAmountOfEntities()
    {
        return ((size_t(__thiscall*)(EntitySystem*))(shared::base + 0x67F860))(this);
    }

    Entity* getEntityAt(size_t at)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, size_t))(shared::base + 0x67F870))(this, at);
    }

    void destroyEntity(eObjID objId)
    {
        ((void(__thiscall*)(EntitySystem*, eObjID))(shared::base + 0x680AD0))(this, objId);
    }

    BOOL destroyDatsuEntity(Entity* datsuEntity)
    {
        return ((BOOL(__thiscall*)(EntitySystem*, Entity*))(shared::base + 0x681410))(this, datsuEntity);
    }

    void update()
    {
        ((void(__thiscall*)(EntitySystem*))(shared::base + 0x6817F0))(this);
    }

    void entitiesShutdown()
    {
        ((void(__thiscall*)(EntitySystem*))(shared::base + 0x6819A0))(this);
    }

    void startup()
    {
        ((void(__thiscall*)(EntitySystem*))(shared::base + 0x681F50))(this);
    }

    void shutdown()
    {
        ((void(__thiscall*)(EntitySystem*))(shared::base + 0x681FF0))(this);
    }

    ~EntitySystem()
    {
        ((void(__thiscall*)(EntitySystem*))(shared::base + 0x6821A0))(this);
    }

    EntitySystem(void* a2)
    {
        ((void(__thiscall*)(EntitySystem*, void*))(shared::base + 0x682230))(this, a2);
    }
    // we don't have default construction
    EntitySystem() = delete;
    EntitySystem(EntitySystem const &) = delete;
    EntitySystem(EntitySystem&&) = delete;

    static inline HandleManager<Entity> &ms_HandleManager = *(HandleManager<Entity>*)(shared::base + 0x17E9A60); // now it makes sense
    static inline EntitySystem& ms_Instance = *(EntitySystem*)(shared::base + 0x17E9A98);
};

EntityHandle::operator Entity *()
{
    unsigned int shifted = (this->m_Handle >> 8);
    if (shifted >= EntitySystem::ms_HandleManager.m_capacity)
    {
        PrintfLog("[HandleManage] Handle error: Invalid handle");
        return nullptr;
    }
    
    if (((this->m_Handle ^ EntitySystem::ms_HandleManager.m_HandleArrayValue[shifted].m_Handle.m_Handle) & 0xFFFFFF00) != 0)
        return nullptr;
        
    return EntitySystem::ms_HandleManager.m_HandleArrayValue[shifted].m_value;
}

struct EntitySystem::SetInfo
{
    short field_0;
    short field_2;
    short field_4;
    int field_8;
    eObjID m_nEntityId;
    cVec3 m_vecBaseRot;
    cVec3 m_vecTrans;
    cVec3 m_vecBaseRotL;
    cVec3 m_vecTransL;
    float m_fRotation;
    int m_nSetType;
    int m_nType;
    int m_nSetRtn;
    int m_nSetFlag;
    int field_54;
    int m_nPathNo;
    int m_nWaypointNo;
    int m_nSetWait;
    int m_nParentId;
    int m_nPartsNo;
    int m_nHashNo;
    int m_nParam;
    int m_nBezierNo;
    int field_78;
    int m_nItemId;
    int m_nGroupPos;
    int field_84;
    int field_88;
    int field_8C;
    Entity* m_pEntity;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    Entity* m_pRoomUnitEntity;
    int m_nInitialRtn;
    float m_fInitialTime;
    cVec3 m_vecInitialPos;
    float m_fInitialPosDirY;
    int field_EC;
    int field_F0;
    int m_nItemAlias;
    char m_Free0;
    char m_DropItemNormal;
    char m_DropItemStealth;
    char m_VisceraTableNo;
    float m_fReflexViewAngY;
    float m_fReflexViewAngX;
    float m_fReflexViewDist;
    float m_fScoutViewAngY;
    float m_fScoutViewAngX;
    float m_fScoutViewDist;
    int field_114;

    SetInfo()
    {
        ((void(__thiscall*)(EntitySystem::SetInfo*))(shared::base + 0xEC5C0))(this);
    };
};

struct EntitySystem::EntityInfo
{
    const char *m_Name;
    eObjID m_nModelIndex;
    eObjID m_nAnimIndex;
    EntitySystem::ObjectInfo *m_pObjectInfo;
    int field_10;
    int field_14;
    Behavior *field_18;
    int field_1C;
    void *m_pModelData;
    void *m_TexturesFile;
    void *m_WtbFile;
    void *m_pParam;

    EntityInfo()
    {
        ((void(__thiscall*)(EntitySystem::EntityInfo*))(shared::base + 0x67CA40))(this);
    }
};

struct EntitySystem::ObjectInfo
{
    int m_nSetType;
    int m_nType;
    int m_nSetRtn;
    int m_nSetFlag;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    cVec3 m_vecTransformPosition;
    cVec3 m_vecRotation;
    cVec3 m_vecSize;
    int field_74;
    int field_78;
    int field_7C;

    ObjectInfo()
    {
        ((void(__thiscall*)(EntitySystem::ObjectInfo*))(shared::base + 0xB190))(this);
    }
};

struct Entity::ConstructInfo
{
    EntitySystem* m_Creator;
    SceneModelSystem* m_ModelSystem;
    int field_8;
    EntitySystem::EntityInfo* m_EntityInfo;
    int field_10;
};

VALIDATE_SIZE(EntitySystem, 0x12C);