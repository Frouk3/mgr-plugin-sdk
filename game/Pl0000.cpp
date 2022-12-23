#include "../shared/shared.h"
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
    ((float (__thiscall *)(Pl0000 *))address)(this);
}