#include "shared.h"
#include "PlayerManagerImplement.h"

PlayerManagerImplement *&g_pPlayerManagerImplement = *(PlayerManagerImplement **)(shared::base + 0x17EA100);

PlayerManagerImplement::PlayerManagerImplement()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x856D60))(this);
}

void PlayerManagerImplement::Tick()
{
    CallVMTFunc<1, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::PreparePlayer()
{
    CallVMTFunc<2, PlayerManagerImplement*>(this);
}

void PlayerManagerImplement::Shutdown()
{
    CallVMTFunc<3, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::SetSlowRate(float SlowRate, int a3, int a4)
{
    CallVMTFunc<7, PlayerManagerImplement *, float, int, int>(this, SlowRate, a3, a4);
}

cVec4 *PlayerManagerImplement::GetPlayerPosition()
{
    return ReturnCallVMTFunc<cVec4 *, 8, PlayerManagerImplement*>(this);
}

Entity *PlayerManagerImplement::GetEntity(int a2)
{
    return ReturnCallVMTFunc<Entity *, 9, PlayerManagerImplement *, int>(this, a2);
}

Entity *PlayerManagerImplement::GetEntityn(int a2)
{
    return ReturnCallVMTFunc<Entity *, 10, PlayerManagerImplement *, int>(this, a2);
}

void PlayerManagerImplement::SetSwordHidden(int shouldHide)
{
    CallVMTFunc<12, PlayerManagerImplement *>(this, shouldHide);
}

void PlayerManagerImplement::CreateBalkanEntity()
{
    CallVMTFunc<16, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::RemoveBalkanEntity()
{
    CallVMTFunc<17, PlayerManagerImplement*>(this);
}

Entity *PlayerManagerImplement::GetBalkanEntity()
{
    return ReturnCallVMTFunc<Entity *, 18, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::SetMainWeaponEquipped(int weaponType)
{
    CallVMTFunc<21, PlayerManagerImplement *, int>(this, weaponType);
}

int PlayerManagerImplement::GetMainWeaponEquipped()
{
    return ReturnCallVMTFunc<int, 22, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::SetCustomWeaponEquipped(int customWeaponType)
{
    CallVMTFunc<24, PlayerManagerImplement *, int>(this, customWeaponType);
}

void PlayerManagerImplement::SetSubWeaponEquipped(int subWeaponType)
{
    CallVMTFunc<25, PlayerManagerImplement *, int>(this, subWeaponType);
}

int PlayerManagerImplement::GetCustomWeaponEquipped()
{
    return ReturnCallVMTFunc<int, 26, PlayerManagerImplement *>(this);
}

int PlayerManagerImplement::GetSubWeaponEquipped()
{
    return ReturnCallVMTFunc<int, 27, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::SetRecoveryEquipped(int recoveryType)
{
    CallVMTFunc<29, PlayerManagerImplement *, int>(this, recoveryType);
}

int PlayerManagerImplement::GetRecoveryEquipped()
{
    return ReturnCallVMTFunc<int, 30, PlayerManagerImplement*>(this);
}

void PlayerManagerImplement::UpdatePlayerStats()
{
    CallVMTFunc<31, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::UpdatePlayerStatsAsRaiden()
{
    CallVMTFunc<32, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::UpgradeHealth()
{
    CallVMTFunc<34, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::DowngradeHealth()
{
    CallVMTFunc<35, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::UpgradeFuelContainer()
{
    CallVMTFunc<36, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::DowngradeFuelContainer()
{
    CallVMTFunc<37, PlayerManagerImplement *>(this);
}

int PlayerManagerImplement::GetHealthUpgrades()
{
    return ReturnCallVMTFunc<int, 38, PlayerManagerImplement *>(this);
}

int PlayerManagerImplement::GetFuelContainerUpgrades()
{
    return ReturnCallVMTFunc<int, 39, PlayerManagerImplement *>(this);
}

bool PlayerManagerImplement::IsPlayerAlive()
{
    return ReturnCallVMTFunc<bool, 40, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::AddBP(int bpCount)
{
    CallVMTFunc<41, PlayerManagerImplement*, int>(this, bpCount);
}

int PlayerManagerImplement::GetBP()
{
    return ReturnCallVMTFunc<int, 42, PlayerManagerImplement *>(this);
}

void PlayerManagerImplement::PreparePl0000()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840850))(this);
}

void PlayerManagerImplement::PreparePl1400()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840B00))(this);
}

void PlayerManagerImplement::PreparePl1500()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x840DA0))(this);
}

PlayerManagerImplement *PlayerManagerImplement::Get()
{
    return ((PlayerManagerImplement *(__cdecl *)())(shared::base + 0x813920))();
}

Entity *PlayerManagerImplement::GetPlayerEntity()
{
    return ((Entity *(__cdecl *)())(shared::base + 0x6C45B0))();
}
