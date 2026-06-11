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
    Hw::cVec4 m_vecPlayerPosition;
    int field_C0;
    int field_C4;
    EntityHandle m_BalkanHandle;
    int m_nMaxHealth;
    float m_fMaxFuelContainer;
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
        MAKE_CALL(shared::base + 0x856D60, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void tick()
    {
        MAKE_VCALL(1, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void preparePlayer()
    {
        MAKE_VCALL(2, void (__thiscall *)(PlayerManagerImplement*), this);
    }

    void shutdown()
    {
        MAKE_VCALL(3, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void setSlowRate(float SlowRate, int a3, int a4)
    {
        MAKE_VCALL(7, void (__thiscall *)(PlayerManagerImplement *, float, int, int), this, SlowRate, a3, a4);
    }

    Hw::cVec4 &getPlayerPosition()
    {
        return MAKE_VCALL(8, Hw::cVec4& (__thiscall *)(PlayerManagerImplement *), this);
    }

    Entity *getEntity(unsigned int index) const
    {
        return MAKE_VCALL(9, Entity *(__thiscall *)(const PlayerManagerImplement *, unsigned int), this, index);
    }

    Entity *getEntity(unsigned int index)
    {
        return MAKE_VCALL(10, Entity *(__thiscall *)(PlayerManagerImplement *, unsigned int), this, index);
    }

    void setSwordHidden(int shouldHide)
    {
        MAKE_VCALL(12, void (__thiscall *)(PlayerManagerImplement *, int), this, shouldHide);
    }

    void createBalkanEntity()
    {
        MAKE_VCALL(16, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void removeBalkanEntity()
    {
        MAKE_VCALL(17, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    Entity *getBalkanEntity()
    {
        return MAKE_VCALL(18, Entity *(__thiscall *)(PlayerManagerImplement *), this);
    }

    void clearKogekkoEntity()
    {
        MAKE_VCALL(20, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void setMainWeaponEquipped(int weaponType)
    {
        MAKE_VCALL(21, void (__thiscall *)(PlayerManagerImplement *, int), this, weaponType);
    }

    int getMainWeaponEquipped()
    {
        return MAKE_VCALL(22, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    void setCustomWeaponEquipped(int customWeaponType)
    {
        MAKE_VCALL(24, void (__thiscall *)(PlayerManagerImplement *, int), this, customWeaponType);
    }

    void setSubWeaponEquipped(int subWeaponType)
    {
        MAKE_VCALL(25, void (__thiscall *)(PlayerManagerImplement *, int), this, subWeaponType);
    }

    int getCustomWeaponEquipped()
    {
        return MAKE_VCALL(26, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    int getSubWeaponEquipped()
    {
        return MAKE_VCALL(27, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    void setRecoveryEquipped(int recoveryType)
    {
        MAKE_VCALL(29, void (__thiscall *)(PlayerManagerImplement *, int), this, recoveryType);
    }

    int getRecoveryEquipped()
    {
        return MAKE_VCALL(30, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    void updatePlayerStats()
    {
        MAKE_VCALL(31, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void updatePlayerStatsAsRaiden()
    {
        MAKE_VCALL(32, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void upgradeHealth()
    {
        MAKE_VCALL(34, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void downgradeHealth()
    {
        MAKE_VCALL(35, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void upgradeFuelContainer()
    {
        MAKE_VCALL(36, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void downgradeFuelContainer()
    {
        MAKE_VCALL(37, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    int getHealthUpgrades()
    {
        return MAKE_VCALL(38, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    int getFuelContainerUpgrades()
    {
        return MAKE_VCALL(39, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    bool isPlayerAlive()
    {
        return MAKE_VCALL(40, bool (__thiscall *)(PlayerManagerImplement *), this);
    }

    void addBP(int bpCount)
    {
        MAKE_VCALL(41, void (__thiscall *)(PlayerManagerImplement *, int), this, bpCount);
    }

    int getBP()
    {
        return MAKE_VCALL(42, int (__thiscall *)(PlayerManagerImplement *), this);
    }

    void preparePl0000()
    {
        MAKE_CALL(shared::base + 0x840850, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void preparePl1400()
    {
        MAKE_CALL(shared::base + 0x840B00, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    void preparePl1500()
    {
        MAKE_CALL(shared::base + 0x840DA0, void (__thiscall *)(PlayerManagerImplement *), this);
    }

    static inline PlayerManagerImplement* get()
    {
        return MAKE_CALL(shared::base + 0x813920, PlayerManagerImplement* (__cdecl *)());
    }

    static inline Entity* getPlayerEntity()
    {
        return MAKE_CALL(shared::base + 0x6C45B0, Entity* (__cdecl *)());
    }
};

inline PlayerManagerImplement *&g_pPlayerManager = *(PlayerManagerImplement**)(shared::base + 0x17EA100);

VALIDATE_SIZE(PlayerManagerImplement, 0x100);