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
  cSlowRateUnit *m_pSlowRateUnit;
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
  SceneModelSystem *m_pSceneModelSystem;
  void *m_pSpecifiedInstance;
  Animation* m_pAnimation;
  int field_44;
  void *m_pInstance;
  BOOL m_bModelRegistered;
  int field_50;
  int field_54;
  int m_nSetType;
  int field_5C;

  struct ConstructInfo;

  BOOL Construct(ConstructInfo *pConstructInfo)
  {
    return ((BOOL (__thiscall *)(Entity *, ConstructInfo *))(shared::base + 0x680E70))(this, pConstructInfo);
  }
  void *GetItemInstance()
  {
    return ((void *(__thiscall *)(Entity *))(shared::base + 0x67C8A0))(this);
  }
  void UpdateSlowRateUnit()
  {
    ((void (__thiscall *)(Entity *))(shared::base + 0xA049A0))(this);
  }
  float GetCalculatedSlowRate()
  {
    return ((float (__thiscall *)(Entity *))(shared::base + 0xA049B0))(this);
  }
  void SetEntitySlowRateType(int SlowRateType)
  {
    ((void (__thiscall *)(Entity *, int))(shared::base + 0xA08640))(this, SlowRateType);
  }
  void SetOffset(cVec4 *offset)
  {
      ((void(__thiscall*)(Entity*, cVec4*))(shared::base + 0x67CE90))(this, offset);
  }
  cVec4* GetOffset()
  {
      return ((cVec4 * (__thiscall*)(Entity*))(shared::base + 0x67C8B0))(this);
  }
  void AddToOffset(cVec4 *offset)
  {
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CEC0))(this, offset);
  }
  void SetRotation(cVec4 *rotation)
  {
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CF00))(this, rotation);
  }
  cVec4 *GetRotation()
  {
    return ((cVec4 *(__thiscall *)(Entity *))(shared::base + 0x67C8D0))(this);
  }
  void SetSize(cVec4 *size)
  {
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CF90))(this, size);
  }
  cVec4 *GetSize()
  {
    return ((cVec4 *(__thiscall *)(Entity *))(shared::base + 0x67C8F0))(this);
  }
};

VALIDATE_SIZE(Entity, 0x60);