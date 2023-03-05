#include "shared.h"
#include "PlayerManagerImplement.h"

PlayerManagerImplement *&g_pPlayerManagerImplement = *(PlayerManagerImplement **)(shared::base + 0x17EA100);

PlayerManagerImplement::PlayerManagerImplement()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x856D60))(this);
}

void PlayerManagerImplement::SetSlowRate(float SlowRate, int a3, int a4)
{
    ((void (__thiscall *)(PlayerManagerImplement *, float, int, int))(shared::base + 0x84CE30))(this, SlowRate, a3, a4);
}

cVec4 *PlayerManagerImplement::GetPlayerPosition()
{
    return ((cVec4 *(__thiscall *)(PlayerManagerImplement *))(shared::base + 0x84CDF0))(this);
}

void PlayerManagerImplement::PreparePlayer()
{
    ((void (__thiscall *)(PlayerManagerImplement *))(shared::base + 0x841040))(this);
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

PlayerManagerImplement *GetPlayerManagerImplement()
{
    return ((PlayerManagerImplement *(__cdecl *)())(shared::base + 0x813920))();
}
