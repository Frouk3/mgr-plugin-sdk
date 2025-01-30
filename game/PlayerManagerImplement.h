#pragma once

#include <PlayerManager.h>
#include <Hw.h>
#include <lib.h>
#include <Entity.h>
#include <shared.h>
#include <Pl0000.h>
#include <Pl1400.h>
#include <Pl1500.h>

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
    EntityHandle m_BalkanHandle;
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
    EntityHandle m_KogekkoEntity;
    
    PlayerManagerImplement()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x856D60))(this);
    }

    void tick()
    {
        CallVMTFunc<1, PlayerManagerImplement *>(this);
    }

    void preparePlayer()
    {
        CallVMTFunc<2, PlayerManagerImplement*>(this);
    }

    void shutdown()
    {
        CallVMTFunc<3, PlayerManagerImplement *>(this);
    }

    void setSlowRate(float SlowRate, int a3, int a4)
    {
        CallVMTFunc<7, PlayerManagerImplement *, float, int, int>(this, SlowRate, a3, a4);
    }

    cVec4 &getPlayerPosition()
    {
        return ReturnCallVMTFunc<cVec4 &, 8, PlayerManagerImplement*>(this);
    }

    Entity *getEntity(unsigned int index) const
    {
        return ReturnCallVMTFunc<Entity *, 9, const PlayerManagerImplement *, unsigned int>(this, index);
    }

    Entity *getEntity(unsigned int index)
    {
        return ReturnCallVMTFunc<Entity *, 10, PlayerManagerImplement *, unsigned int>(this, index);
    }

    void setSwordHidden(int shouldHide)
    {
        CallVMTFunc<12, PlayerManagerImplement *>(this, shouldHide);
    }

    void createBalkanEntity()
    {
        CallVMTFunc<16, PlayerManagerImplement *>(this);
    }

    void removeBalkanEntity()
    {
        CallVMTFunc<17, PlayerManagerImplement*>(this);
    }

    Entity *getBalkanEntity()
    {
        return ReturnCallVMTFunc<Entity *, 18, PlayerManagerImplement *>(this);
    }

    void clearKogekkoEntity()
    {
        CallVMTFunc<20, PlayerManagerImplement *>(this);
    }

    void setMainWeaponEquipped(int weaponType)
    {
        CallVMTFunc<21, PlayerManagerImplement *, int>(this, weaponType);
    }

    int getMainWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 22, PlayerManagerImplement *>(this);
    }

    void setCustomWeaponEquipped(int customWeaponType)
    {
        CallVMTFunc<24, PlayerManagerImplement *, int>(this, customWeaponType);
    }

    void setSubWeaponEquipped(int subWeaponType)
    {
        CallVMTFunc<25, PlayerManagerImplement *, int>(this, subWeaponType);
    }

    int getCustomWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 26, PlayerManagerImplement *>(this);
    }

    int getSubWeaponEquipped()
    {
        return ReturnCallVMTFunc<int, 27, PlayerManagerImplement *>(this);
    }

    void setRecoveryEquipped(int recoveryType)
    {
        CallVMTFunc<29, PlayerManagerImplement *, int>(this, recoveryType);
    }

    int getRecoveryEquipped()
    {
        return ReturnCallVMTFunc<int, 30, PlayerManagerImplement*>(this);
    }

    void updatePlayerStats()
    {
        CallVMTFunc<31, PlayerManagerImplement *>(this);
    }

    void updatePlayerStatsAsRaiden()
    {
        CallVMTFunc<32, PlayerManagerImplement *>(this);
    }

    void upgradeHealth()
    {
        CallVMTFunc<34, PlayerManagerImplement *>(this);
    }

    void downgradeHealth()
    {
        CallVMTFunc<35, PlayerManagerImplement *>(this);
    }

    void upgradeFuelContainer()
    {
        CallVMTFunc<36, PlayerManagerImplement *>(this);
    }

    void downgradeFuelContainer()
    {
        CallVMTFunc<37, PlayerManagerImplement *>(this);
    }

    int getHealthUpgrades()
    {
        return ReturnCallVMTFunc<int, 38, PlayerManagerImplement *>(this);
    }

    int getFuelContainerUpgrades()
    {
        return ReturnCallVMTFunc<int, 39, PlayerManagerImplement *>(this);
    }

    bool isPlayerAlive()
    {
        return ReturnCallVMTFunc<bool, 40, PlayerManagerImplement *>(this);
    }

    void addBP(int bpCount)
    {
        CallVMTFunc<41, PlayerManagerImplement*, int>(this, bpCount);
    }

    int getBP()
    {
        return ReturnCallVMTFunc<int, 42, PlayerManagerImplement *>(this);
    }

    void preparePl0000()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840850))(this);
    }

    void preparePl1400()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840B00))(this);
    }

    void preparePl1500()
    {
        ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840DA0))(this);
    }

    static inline PlayerManagerImplement* get()
    {
        return ((PlayerManagerImplement *(__cdecl *)())(shared::base + 0x813920))();
    }

    static inline Entity* getPlayerEntity()
    {
        return ((Entity *(__cdecl *)())(shared::base + 0x6C45B0))();
    }

    static inline PlayerManagerImplement *&ms_Instance = *(PlayerManagerImplement **)(shared::base + 0x17EA100);
};

VALIDATE_SIZE(PlayerManagerImplement, 0x100);