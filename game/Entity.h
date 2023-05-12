#pragma once
#include "cSlowRateUnit.h"
#include "SceneModelSystem.h"
#include "cVec4.h"
#include "Hw.h"

struct Animation;

struct Entity
{
  cSlowRateUnit *m_pSlowRateUnit;
  int field_4;
  int field_8;
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
  SceneModelSystem *m_pSceneModelSystem;
  void *m_pSpecifiedInstance;
  Animation* m_pAnimation;
  int field_44;
  void *m_pInstance;
  int field_4C;
  int field_50;
  int field_54;
  int field_58;
  int field_5C;
  int field_60;
  int field_64;
  int field_68;
  int field_6C;
  int field_70;
  int field_74;
  int field_78;
  Hw::cHeapFixed* m_pcHeapFixed;

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