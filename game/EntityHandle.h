#pragma once
#include "cSlowRateUnit.h"
#include "SceneModelSystem.h"

struct EntityHandle
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
  SceneModelSystem *field_38;
  void *m_pSpecifiedInstance;
  int field_40;
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
  int field_7C;

  void *GetItemInstance() noexcept;
  void UpdateSlowRateUnit() noexcept;
  float GetCalculatedSlowRate() noexcept;
  void SetEntitySlowRateType(int SlowRateType) noexcept;
};