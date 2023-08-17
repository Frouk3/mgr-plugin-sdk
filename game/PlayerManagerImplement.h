#pragma once
#include "PlayerManager.h"
#include "cVec4.h"
#include "Hw.h"
#include "lib.h"
#include "Entity.h"
#include "shared.h"

class PlayerManagerImplement : public PlayerManager
{
public:
    EntityHandle field_4; // EntityHandle (??)
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
    lib::StaticArray<EntityHandle, 2> *m_pEntityArray;
    EntityHandle field_FC; // EntityHandle (??)
    
    PlayerManagerImplement()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x856D60))(this);
    }
    virtual ~PlayerManagerImplement() override {};
    void Tick()
    {
        CallVMTFunc<1, PlayerManagerImplement *>(this);
    }
    void PreparePlayer()
    {
        CallVMTFunc<2, PlayerManagerImplement*>(this);
    }
    void Shutdown()
    {
        CallVMTFunc<3, PlayerManagerImplement *>(this);
    }
    void SetSlowRate(float SlowRate, int a3, int a4)
    {
        CallVMTFunc<7, PlayerManagerImplement *, float, int, int>(this, SlowRate, a3, a4);
    }
    cVec4 *GetPlayerPosition()
    {
        return ReturnCallVMTFunc<cVec4 *, 8, PlayerManagerImplement*>(this);
    }
    Entity *GetEntity(int a2)
    {
        return ReturnCallVMTFunc<Entity *, 9, PlayerManagerImplement *, int>(this, a2);
    }
    // duplicate of GetEntity?
    Entity *GetEntityn(int a2)
    {
        return ReturnCallVMTFunc<Entity *, 10, PlayerManagerImplement *, int>(this, a2);
    }
    void SetSwordHidden(int shouldHide)
    {
        CallVMTFunc<12, PlayerManagerImplement *>(this, shouldHide);
    }
    void CreateBalkanEntity()
    {
        CallVMTFunc<16, PlayerManagerImplement *>(this);
    }
    void RemoveBalkanEntity()
    {
        CallVMTFunc<17, PlayerManagerImplement*>(this);
    }
    Entity *GetBalkanEntity()
    {
        return ReturnCallVMTFunc<Entity *, 18, PlayerManagerImplement *>(this);
    }
    void SetMainWeaponEquipped(int weaponType)
    {
        CallVMTFunc<21, PlayerManagerImplement *, int>(this, weaponType);
    }
    int GetMainWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 22, PlayerManagerImplement *>(this);
    }
    void SetCustomWeaponEquipped(int customWeaponType)
    {
        CallVMTFunc<24, PlayerManagerImplement *, int>(this, customWeaponType);
    }
    void SetSubWeaponEquipped(int subWeaponType)
    {
        CallVMTFunc<25, PlayerManagerImplement *, int>(this, subWeaponType);
    }
    int GetCustomWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 26, PlayerManagerImplement *>(this);
    }
    int GetSubWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 27, PlayerManagerImplement *>(this);
    }
    void SetRecoveryEquipped(int recoveryType)
    {
        CallVMTFunc<29, PlayerManagerImplement *, int>(this, recoveryType);
    }
    int GetRecoveryEquipped()
    {
        return ReturnCallVMTFunc<int, 30, PlayerManagerImplement*>(this);
    }
    void UpdatePlayerStats()
    {
        CallVMTFunc<31, PlayerManagerImplement *>(this);
    }
    void UpdatePlayerStatsAsRaiden()
    {
        CallVMTFunc<32, PlayerManagerImplement *>(this);
    }
    void UpgradeHealth()
    {
        CallVMTFunc<34, PlayerManagerImplement *>(this);
    }
    void DowngradeHealth()
    {
        CallVMTFunc<35, PlayerManagerImplement *>(this);
    }
    void UpgradeFuelContainer()
    {
        CallVMTFunc<36, PlayerManagerImplement *>(this);
    }
    void DowngradeFuelContainer()
    {
        CallVMTFunc<37, PlayerManagerImplement *>(this);
    }
    int GetHealthUpgrades()
    {
        return ReturnCallVMTFunc<int, 38, PlayerManagerImplement *>(this);
    }
    int GetFuelContainerUpgrades()
    {
        return ReturnCallVMTFunc<int, 39, PlayerManagerImplement *>(this);
    }
    bool IsPlayerAlive()
    {
        return ReturnCallVMTFunc<bool, 40, PlayerManagerImplement *>(this);
    }
    void AddBP(int bpCount)
    {
        CallVMTFunc<41, PlayerManagerImplement*, int>(this, bpCount);
    }
    int GetBP()
    {
        return ReturnCallVMTFunc<int, 42, PlayerManagerImplement *>(this);
    }
    void PreparePl0000()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840850))(this);
    }
    void PreparePl1400()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840B00))(this);
    }
    void PreparePl1500()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840DA0))(this);
    }

    static inline PlayerManagerImplement* Get()
    {
        return ((PlayerManagerImplement *(__cdecl *)())(shared::base + 0x813920))();
    }

    static inline Entity* GetPlayerEntity()
    {
        return ((Entity *(__cdecl *)())(shared::base + 0x6C45B0))();
    }

    static inline PlayerManagerImplement *&pInstance = *(PlayerManagerImplement **)(shared::base + 0x17EA100);
};

VALIDATE_SIZE(PlayerManagerImplement, 0x100);