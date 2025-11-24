#pragma once

#include <Hw.h>
#include <SceneModelSystem.h>
#include <Entity.h>
#include <Behavior.h>
#include <EntityHandle.h>
#include <common.h>
#include <SceneBehaviorSystem.h>

struct EntitySystem
{
    struct EntityCreationData
    {
        eObjID m_ObjectID;
        void *(__cdecl *m_pfnConstructor)(Hw::cHeap *);
        int field_8;
        const char *m_className;
    };

    size_t m_EntityCapacity; // how much entities can we hold?
    Hw::cHeap* m_pHeap;
    SceneModelSystem* m_pSceneModelSystem;
    BehaviorList *m_pBehaviorList;
    int field_10;
    int field_14;
    Hw::cCriticalSection m_EntityListSection;
    int field_34;
    Hw::cFixedList<Entity *> m_EntityList;
    int field_54;
    int field_58;
    int field_5C;
    Hw::cHeapFixed m_HeapFixed;
    Hw::cCriticalSection m_EntitySpawnSection;
    int field_DC;
    lib::AllocatedArray<Entity *> field_E0;
    lib::AllocatedArray<Entity *> m_DatsuArray;
    Hw::cCriticalSection field_110;

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

    Entity* getClosestEntity(eObjID objId, const Hw::cVec4& position, const float distance)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, eObjID, const Hw::cVec4&, const float))(shared::base + 0x67F660))(this, objId, position, distance);
    }

    Entity* findEntity(const char* name, eObjID objId)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, const char*, eObjID))(shared::base + 0x67F710))(this, name, objId);
    }

    Entity* getClosestEntity(eObjID objId, const Hw::cVec4& position)
    {
        return ((Entity * (__thiscall*)(EntitySystem*, eObjID, const Hw::cVec4&))(shared::base + 0x67F7B0))(this, objId, position);
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
    /*
    from what I can say from the field down below, it seems that PlatinumGames had their own way of adding entities without troubles, as if creating array of data with different functions and data would be pain in ass
    */

    static inline EntitySystem::EntityCreationData* ms_aEntities = (EntitySystem::EntityCreationData*)(shared::base + 0x14A1D70); // max 791
};

inline HandleManager<Entity> &g_EntityHandleManager = *(HandleManager<Entity>*)(shared::base + 0x17E9A60); // now it makes sense
inline EntitySystem& g_EntitySystem = *(EntitySystem*)(shared::base + 0x17E9A98);

struct EntitySystem::SetInfo
{
    short field_0;
    short field_2;
    short field_4;
    int field_8;
    eObjID m_EntityId;
    Hw::cVec3 m_BaseRot;
    Hw::cVec3 m_Trans;
    Hw::cVec3 m_BaseRotL;
    Hw::cVec3 m_TransL;
    float m_Rotation;
    int m_SetType;
    int m_Type;
    int m_SetRtn;
    int m_SetFlag;
    int field_54;
    int m_PathNo;
    int m_WaypointNo;
    int m_SetWait;
    int m_ParentId;
    int m_PartsNo;
    int m_HashNo;
    int m_Param;
    int m_BezierNo;
    int field_78;
    int m_ItemId;
    int m_GroupPos;
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
    int m_InitialRtn;
    float m_InitialTime;
    Hw::cVec3 m_InitialPos;
    float m_InitialPosDirY;
    int field_EC;
    int field_F0;
    int m_ItemAlias;
    char m_Free0;
    char m_DropItemNormal;
    char m_DropItemStealth;
    char m_VisceraTableNo;
    float m_ReflexViewAngY;
    float m_ReflexViewAngX;
    float m_ReflexViewDist;
    float m_ScoutViewAngY;
    float m_ScoutViewAngX;
    float m_ScoutViewDist;
    int field_114;

    SetInfo()
    {
        ((void(__thiscall*)(EntitySystem::SetInfo*))(shared::base + 0xEC5C0))(this);
    };
};

struct EntitySystem::EntityInfo
{
    const char *m_pName;
    eObjID m_ModelIndex;
    eObjID m_ObjectIndex;
    EntitySystem::ObjectInfo *m_pObjectInfo;
    int field_10;
    int field_14;
    Behavior *m_pCopyBehavior;
    int field_1C;
    void *m_pModelData; // wmb
    void *m_pTexturesFile;
    void *m_pWtbFile;
    void *m_pParam;

    EntityInfo()
    {
        ((void(__thiscall*)(EntitySystem::EntityInfo*))(shared::base + 0x67CA40))(this);
    }
};

struct EntitySystem::ObjectInfo
{
    int m_SetType;
    int m_Type;
    int m_SetRtn;
    int m_SetFlag;
    Hw::cMtx m_WorldMatrix;
    Hw::cVec3 m_TransPos;
    Hw::cVec3 m_Rot;
    Hw::cVec3 m_Scale;
    int field_74;
    void *m_pModel;
    int field_7C;

    ObjectInfo()
    {
        ((void(__thiscall*)(EntitySystem::ObjectInfo*))(shared::base + 0xB190))(this);
    }
};

struct Entity::ConstructInfo
{
    EntitySystem* m_pCreator;
    SceneModelSystem* m_pSceneModelManager;
    BehaviorList *m_pBehaviorList;
    EntitySystem::EntityInfo* m_pEntityInfo;
    int field_10;
};

VALIDATE_SIZE(EntitySystem, 0x12C);