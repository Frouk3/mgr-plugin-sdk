#include "shared.h"
#include "PlayerManagerImplement.h"

PlayerManagerImplement *g_pPlayerManagerImplement = *(PlayerManagerImplement **)(shared::base + 0x17EA100);

PlayerManagerImplement::PlayerManagerImplement() noexcept
{
    DWORD address = shared::base + 0x856D60;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

PlayerManagerImplement::~PlayerManagerImplement() noexcept
{
    DWORD address = shared::base + 0x84CEB0;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

void PlayerManagerImplement::SetSlowRate(float SlowRate, int a3, int a4) noexcept
{
    DWORD address = shared::base + 0x84CE30;
    ((void (__thiscall *)(PlayerManagerImplement *, float, int, int))address)(this, SlowRate, a3, a4);
}

cVec4 *PlayerManagerImplement::GetPlayerPosition() noexcept
{
    DWORD address = shared::base + 0x84CDF0;
    return ((cVec4 *(__thiscall *)(PlayerManagerImplement *))address)(this);
}

void PlayerManagerImplement::PreparePlayer() noexcept
{
    DWORD address = shared::base + 0x841040;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

void PlayerManagerImplement::PreparePl0000() noexcept
{
    DWORD address = shared::base + 0x840850;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

void PlayerManagerImplement::PreparePl1400() noexcept
{
    DWORD address = shared::base + 0x840B00;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

void PlayerManagerImplement::PreparePl1500() noexcept
{
    DWORD address = shared::base + 0x840DA0;
    ((void (__thiscall *)(PlayerManagerImplement *))address)(this);
}

PlayerManagerImplement *GetPlayerManagerImplement() noexcept
{
    DWORD address = shared::base + 0x813920;
    return ((PlayerManagerImplement *(__cdecl *)())address)();
}
