#pragma once
#include "PlayerManager.h"
#include "cVec4.h"
#include "Hw.h"
#include "lib.h"

class PlayerManagerImplement : public PlayerManager
{
public:
  int field_4;
  int field_8;
  Hw::cTexture field_C[4];
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
  int m_nMainWeaponEquipped;
  int m_nCustomWeaponEquipped;
  int m_nSubWeaponEquipped;
  int m_nRecoveryEquipped;
  int field_F0;
  int field_F4;
  lib::StaticArray<int, 2> *m_pEntityArray;
  DWORD *field_FC;
  
  PlayerManagerImplement();
  virtual ~PlayerManagerImplement() override {};

  void SetSlowRate(float SlowRate, int a3, int a4);
  cVec4 *GetPlayerPosition();
  void PreparePlayer();
  void PreparePl0000();
  void PreparePl1400();
  void PreparePl1500();
};

PlayerManagerImplement *GetPlayerManagerImplement();

extern PlayerManagerImplement *&g_pPlayerManagerImplement;

VALIDATE_SIZE(PlayerManagerImplement, 0x100);