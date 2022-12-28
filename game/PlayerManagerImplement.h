#pragma once
#include "PlayerManager.h"
#include "cVec4.h"

class PlayerManagerImplement : public PlayerManager
{
public:
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
  int field_60;
  int field_64;
  int field_68;
  int field_6C;
  int field_70;
  int field_74;
  int field_78;
  int field_7C;
  int field_80;
  int field_84;
  int field_88;
  int field_8C;
  int field_90;
  int field_94;
  float m_fSlowRate;
  int field_9C;
  int field_A0;
  int field_A4;
  int field_A8;
  int field_AC;
  cVec4 m_vecPlayerPosition;
  int field_C0;
  int field_C4;
  int field_C8;
  int m_nMaxHealth;
  float m_nMaxFuelContainer;
  int m_nHealthBonus;
  int m_nFuelContainerBonus;
  int m_nBattlePoints;
  int field_E0;
  int field_E4;
  int field_E8;
  int field_EC;
  int field_F0;
  int field_F4;
  int *field_F8;
  int *field_FC;
  
  PlayerManagerImplement() noexcept;
  ~PlayerManagerImplement() noexcept;

  void SetSlowRate(float SlowRate, int a3, int a4) noexcept;
  cVec4 *GetPlayerPosition() noexcept;
  void PreparePlayer() noexcept;
  void PreparePl0000() noexcept;
  void PreparePl1400() noexcept;
  void PreparePl1500() noexcept;
};

extern PlayerManagerImplement *g_pPlayerManagerImplement;