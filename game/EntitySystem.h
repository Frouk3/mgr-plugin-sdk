#pragma once
#include "Hw.h"
#include "SceneModelSystem.h"
#include "Entity.h"
#include "cVec3.h"
#include "Behavior.h"

struct EntitySystem
{
  int m_nMaxSize;
  Hw::cHeapVariable *m_pHeapVariable;
  SceneModelSystem *m_pSceneModelSystem;
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
  int field_34;
  int field_38;
  int field_3C;
  int field_40;
  int field_44;
  int field_48;
  Entity** m_pStartEntityArray; // for (Entity **i = this->m_pStartEntityArray; i != this->m_pEndEntityArray; i = (Entity**)i[2])
  Entity** m_pEndEntityArray;
  int field_54;
  int field_58;
  int field_5C;
  Hw::cHeapFixed m_HeapFixed;
  int field_B8;
  int field_BC;
  int field_C0;
  int field_C4;
  int field_C8;
  int field_CC;
  int field_D0;
  int field_D4;
  int field_D8;
  int field_DC;
  int field_E0;
  int field_E4;
  int field_E8;
  int field_EC;
  int field_F0;
  int field_F4;
  int field_F8;
  int field_FC;
  int field_100;
  int field_104;
  int field_108;
  int field_10C;
  int field_110;
  int field_114;
  int field_118;
  int field_11C;
  int field_120;
  int field_124;
  int field_128;

  struct EnemySpawnInfo;
  struct EntityInfo;
  struct ObjectInfo;
  Entity *ConstructEntity(const char* name, unsigned int index, ObjectInfo *pObjInfo)
  {
    return ((Entity *(__thiscall *)(EntitySystem *, const char*, unsigned int, ObjectInfo *))(shared::base + 0x682090))(this, name, index, pObjInfo);
  }
  Entity *ConstructEntity(EntityInfo *pInfo)
  {
    return ((Entity *(__thiscall *)(EntitySystem*, EntityInfo *))(shared::base + 0x681B80))(this, pInfo);
  }
};

struct EntitySystem::EnemySpawnInfo
{
  short field_0;
  short field_2;
  short field_4;
  int field_8;
  int m_nEntityId;
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
  int field_90;
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
  int field_D0;
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

  EnemySpawnInfo()
  {
      ((void(__thiscall*)(EntitySystem::EnemySpawnInfo*))(shared::base + 0xEC5C0))(this);
  };
};

struct EntitySystem::EntityInfo
{
  char *m_Name;
  int m_nModelIndex;
  int m_nAnimIndex;
  EntitySystem::ObjectInfo *m_pObjectInfo;
  int field_10;
  int field_14;
  Behavior *field_18;
  int field_1C;
  void *m_pModelData;
  int field_24;
  int field_28;
  void *m_pParam;

  EntityInfo()
  {
    ((void (__thiscall *)(EntitySystem::EntityInfo *))(shared::base + 0x67CA40))(this);
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
    ((void (__thiscall *)(EntitySystem::ObjectInfo *))(shared::base + 0xB190))(this);
  }
};

struct Entity::ConstructInfo
{
  EntitySystem *m_pEntitySystem;
  SceneModelSystem *m_pSceneModelSystem;
  int field_8;
  EntitySystem::EntityInfo *m_pEntityInfo;
  int field_10;
};

static EntitySystem &g_EntitySystem = *(EntitySystem*)(shared::base + 0x17E9A98);


VALIDATE_SIZE(EntitySystem, 0x12C);