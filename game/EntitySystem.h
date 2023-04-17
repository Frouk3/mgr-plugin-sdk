#pragma once
#include "Hw.h"
#include "SceneModelSystem.h"
#include "Entity.h"

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
  int field_4C;
  int field_50;
  int field_54;
  int field_58;
  int field_5C;
  Hw::cHeapFixed m_HeapFixed;
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

  Entity *ConstructEntity(const char* name, unsigned int index, void *pInfo = nullptr);
  Entity *ConstructEntity(void *pInfo);
};

extern EntitySystem &g_EntitySystem;


VALIDATE_SIZE(EntitySystem, 0x12C);