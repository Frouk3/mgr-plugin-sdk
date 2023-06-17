#pragma once
#include "cSlowRateUnit.h"
#include "SceneModelSystem.h"
#include "cVec4.h"
#include "Hw.h"
#include "Animation.h"

typedef unsigned int EntityHandle;

struct Entity
{
  cSlowRateUnit *m_pSlowRateUnit;
  char m_EntityName[16];
  int field_14;
  int field_18;
  int field_1C;
  int field_20;
  unsigned int m_nEntityIndex;
  unsigned int m_nEntityFlags;
  int field_2C;
  int field_30;
  int field_34;
  SceneModelSystem *m_pSceneModelSystem;
  void *m_pSpecifiedInstance;
  Animation* m_pAnimation;
  int field_44;
  void *m_pInstance;
  int field_4C;
  int field_50;
  int field_54;
  int m_nSetType;
  int field_5C;

  void *GetItemInstance();
  void UpdateSlowRateUnit();
  float GetCalculatedSlowRate();
  void SetEntitySlowRateType(int SlowRateType);
  void SetOffset(cVec4 *offset);
  cVec4* GetOffset();
  void AddToOffset(cVec4 *offset);
  void SetRotation(cVec4 *rotation);
  cVec4 *GetRotation();
  void SetSize(cVec4 *size);
  cVec4 *GetSize();
};

VALIDATE_SIZE(Entity, 0x60);