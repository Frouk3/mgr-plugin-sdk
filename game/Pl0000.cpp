#include "shared.h"
#include "Pl0000.h"

Pl0000::Pl0000() noexcept
{
    DWORD address = shared::base + 0x6C0310;
    ((void (__thiscall *)(Pl0000 *))address)(this);
}

Pl0000::~Pl0000() noexcept
{
    DWORD address = shared::base + 0x6C13C0;
    ((void (__thiscall *)(Pl0000 *))address)(this);
}

void Pl0000::SetSlowMo(float Duration, float SlowRate) noexcept
{
    DWORD address = shared::base + 0x77AB80;
    ((void (__thiscall *)(Pl0000 *))address)(this);
}

void Pl0000::EnableRipperMode() noexcept
{
    DWORD address = shared::base + 0x785190;
    ((void (__thiscall *)(Pl0000 *))address)(this);
}

void Pl0000::SetFuelContainer(float FuelContainer) noexcept
{
    DWORD address = shared::base + 0x7C3100;
    ((void (__thiscall *)(Pl0000 *))address)(this);
}

void Pl0000::DisableRipperMode(bool bUseFade) noexcept
{
    DWORD address = shared::base + 0x7D9590;
    ((void (__thiscall *)(Pl0000 *, bool))address)(this, bUseFade);
}

float Pl0000::GetMaxFuelContainer() noexcept
{
    DWORD address = shared::base + 0x7DA020;
    return ((float (__thiscall *)(Pl0000 *))address)(this);
}

bool Pl0000::IsParrying() noexcept
{
    DWORD address = shared::base + 0x6C0B30;
    return ((bool (__thiscall *)(Pl0000 *))address)(this);
}

bool Pl0000::IsOnGround() noexcept
{
    DWORD address = shared::base + 0x6C0BB0;
    return ((bool (__thiscall *)(Pl0000 *))address)(this);
}

bool Pl0000::IsInAir() noexcept
{
    DWORD address = shared::base + 0x77C730;
    return ((bool (__thiscall *)(Pl0000 *))address)(this);
}

void Pl0000::CallEffect(int id, cEspControler *esp) noexcept
{
    DWORD address = shared::base + 0x7C3470;
    ((void(__thiscall *)(Pl0000*, int, cEspControler *))address)(this, id, esp);
}