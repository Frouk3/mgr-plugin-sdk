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

	size_t m_EntityCap; // how much entities can we hold?
	Hw::cHeap* m_pHeap;
	SceneModelSystem* m_pSceneModelSystem;
	BehaviorList *m_pBehaviorList;
	int field_10;
	int m_bUseDebris;
	Hw::cCriticalSection m_EntityListSection;
	int field_34;
	Hw::cFixedList<Entity *> m_EntityList;
	int field_54;
	Hw::cFactoryFixed<Entity, 32> m_EntityFactory;
	Hw::cCriticalSection m_EntitySpawnSection;
	int field_DC;
	lib::AllocatedArray<Entity *> field_E0;
	lib::AllocatedArray<Entity *> m_DatsuArray;
	Hw::cCriticalSection field_110;

	struct SetInfo;
	struct EntityInfo;
	struct ObjectInfo;

	Hw::cFixedList<Entity*>& getEntityList() const { return ReturnCallMethod<Hw::cFixedList<Entity*>&, 0x67CA20, const EntitySystem*>(this); }

	void getEntities(eObjID id, lib::Array<Entity*>& pArray) { CallMethod<0x67F440, EntitySystem*, lib::Array<Entity*>&>(this, pArray); }
	void getEntities(eObjID id, lib::Array<EntityHandle>& pArray) { CallMethod<0x67F4A0, EntitySystem*, lib::Array<EntityHandle>&>(this, pArray); }
	void getEntities(eObjID id, unsigned int hashNo, lib::Array<EntityHandle>& pArray) { CallMethod<0x67F520, EntitySystem*, eObjID, unsigned int, lib::Array<EntityHandle>&>(this, id, hashNo, pArray); }
	int getEntityCount(eObjID objID) { return ReturnCallMethod<int, 0x67F5B0, EntitySystem*, eObjID>(this, objID); }
	// usually finds only first entity with given objID
	Entity* getUniqueEntity(eObjID objID) { return ReturnCallMethod<Entity*, 0x67F600, EntitySystem*, eObjID>(this, objID); }
	Entity* getEntityAtTrans(eObjID objID, const Hw::cVec4& position, float maxDistance) { return ReturnCallMethod<Entity*, 0x67F660, EntitySystem*, eObjID, const Hw::cVec4&, float>(this, objID, position, maxDistance); }
	Entity* getUniqueEntity(const char* name, eObjID objID) { return ReturnCallMethod<Entity*, 0x67F710, EntitySystem*, const char*, eObjID>(this, name, objID); }
	Entity* getEntityAtTrans(eObjID objID, const Hw::cVec4& position) { return ReturnCallMethod<Entity*, 0x67F7B0, EntitySystem*, eObjID, const Hw::cVec4&>(this, objID, position); }
	int getEntityNum() { return ReturnCallMethod<int, 0x67F860, EntitySystem*>(this); }
	Entity* getEntityAtNum(int at) { return ReturnCallMethod<Entity*, 0x67F870, EntitySystem*, int>(this, at); }
	void releaseEntities(eObjID objID) { CallMethod<0x680AD0, EntitySystem*, eObjID>(this, objID); }

	void update() { CallMethod<0x6817F0, EntitySystem*>(this); }
	void inurnForce() { CallMethod<0x6819A0, EntitySystem*>(this); }
	Entity* createEntity(EntityInfo& pInfo) { return ReturnCallMethod<Entity*, 0x681B80, EntitySystem*, EntityInfo&>(this, pInfo); }

	BOOL addDatsuEntity(Entity* pDatsuEntity) { return ReturnCallMethod<BOOL, 0x67F3B0, EntitySystem*, Entity*>(this, pDatsuEntity); }

	void startup() { CallMethod<0x681F50, EntitySystem*>(this); }
	void cleanup() { CallMethod<0x681FF0, EntitySystem*>(this); }

	Entity* createEntity(const char* name, eObjID objID, ObjectInfo* pObjInfo) { return ReturnCallMethod<Entity*, 0x682090, EntitySystem*, const char*, eObjID, ObjectInfo*>(this, name, objID, pObjInfo); }

	EntitySystem(void* a2)
	{
		((void(__thiscall*)(EntitySystem*, void*))(shared::base + 0x682230))(this, a2);
	}

	~EntitySystem()
	{
		((void(__thiscall*)(EntitySystem*))(shared::base + 0x6821A0))(this);
	}

	// we don't have default construction
	EntitySystem() = delete;
	EntitySystem(EntitySystem const &) = delete;
	EntitySystem(EntitySystem&&) = delete;
	/*
	from what I can say from the field down below, it seems that PlatinumGames had their own way of adding entities without troubles, as if creating array of data with different functions and data would be pain in ass
	*/
	static inline HandleManager<Entity> m_EntityHandleMan = *(HandleManager<Entity>*)(shared::base + 0x17E9A60);

	static inline EntitySystem::EntityCreationData* ms_aEntities = (EntitySystem::EntityCreationData*)(shared::base + 0x14A1D70); // max 791
};

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