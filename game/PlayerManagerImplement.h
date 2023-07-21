#pragma once
#include "PlayerManager.h"
#include "cVec4.h"
#include "Hw.h"
#include "lib.h"
#include "Entity.h"

class PlayerManagerImplement : public PlayerManager
{
public:
  unsigned int field_4; // EntityHandle (??)
  int field_8;
  Hw::cTexture m_PlayerTextures[5];
  float m_fSlowRate;
  int field_9C;
  int field_A0;
  int field_A4;
  int field_A8;
  int field_AC;
  cVec4 m_vecPlayerPosition;
  int field_C0;
  int field_C4;
  int m_nBalkanHandle;
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
  unsigned int field_FC; // EntityHandle (??)
  
  PlayerManagerImplement();
  virtual ~PlayerManagerImplement() override {};

  void SetSlowRate(float SlowRate, int a3, int a4);
  void Tick();
  void PreparePlayer();
  void Shutdown();
  cVec4 *GetPlayerPosition();
  Entity *GetEntity(int a2);
  Entity *GetEntityn(int a2); // duplicate??
  void SetSwordHidden(int shouldHide); // idfk how is this hides the sword
  void CreateBalkanEntity();
  void RemoveBalkanEntity();
  Entity *GetBalkanEntity();
  void SetMainWeaponEquipped(int weaponType);
  int GetMainWeaponEquipped();
  void SetCustomWeaponEquipped(int customWeaponType);
  void SetSubWeaponEquipped(int subWeaponType);
  int GetCustomWeaponEquipped();
  int GetSubWeaponEquipped();
  void SetRecoveryEquipped(int recoveryType);
  int GetRecoveryEquipped();
  void UpdatePlayerStats();
  void UpdatePlayerStatsAsRaiden();
  void UpgradeHealth();
  void DowngradeHealth();
  void UpgradeFuelContainer();
  void DowngradeFuelContainer();
  int GetHealthUpgrades();
  int GetFuelContainerUpgrades();
  bool IsPlayerAlive();
  void AddBP(int bpCount);
  int GetBP();
  void PreparePl0000();
  void PreparePl1400();
  void PreparePl1500();

  static inline PlayerManagerImplement* Get();
  static inline Entity* GetPlayerEntity();
};

extern PlayerManagerImplement *&g_pPlayerManagerImplement;

VALIDATE_SIZE(PlayerManagerImplement, 0x100);