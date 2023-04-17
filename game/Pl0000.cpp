#include "shared.h"
#include "Pl0000.h"

Pl0000::Pl0000()
{
    ((void (__thiscall *)(Pl0000 *))(shared::base + 0x6C0310))(this);
}

void Pl0000::SetSlowMo(float Duration, float SlowRate)
{
    ((void (__thiscall *)(Pl0000 *, float, float))(shared::base + 0x77AB80))(this, Duration, SlowRate);
}

void Pl0000::EnableRipperMode()
{
    ((void (__thiscall *)(Pl0000 *))(shared::base + 0x785190))(this);
}

void Pl0000::SetFuelContainer(float FuelContainer)
{
    ((void (__thiscall *)(Pl0000 *, float))(shared::base + 0x7C3100))(this, FuelContainer);
}

void Pl0000::DisableRipperMode(bool bUseFade)
{
    ((void (__thiscall *)(Pl0000 *, bool))(shared::base + 0x7D9590))(this, bUseFade);
}

float Pl0000::GetMaxFuelContainer()
{
    return ((float (__thiscall *)(Pl0000 *))(shared::base + 0x7DA020))(this);
}

bool Pl0000::IsParrying()
{
    return ((bool (__thiscall *)(Pl0000 *))(shared::base + 0x6C0B30))(this);
}

bool Pl0000::IsOnGround()
{
    return ((bool (__thiscall *)(Pl0000 *))(shared::base + 0x6C0BB0))(this);
}

bool Pl0000::IsInAir()
{
    return ((bool (__thiscall *)(Pl0000 *))(shared::base + 0x77C730))(this);
}

void Pl0000::CallEffect(int id, cEspControler *esp)
{
    ((void(__thiscall *)(Pl0000*, int, cEspControler *))(shared::base + 0x7C3470))(this, id, esp);
}

int Pl0000::GetMaxHealth()
{
    return ((int(__thiscall *)(Pl0000 *))(shared::base + 0x77C980))(this);
}

cVec4 Pl0000::GetPosForCamera()
{
    return ((cVec4 (__thiscall *)(Pl0000 *))(shared::base + 0x6C0C60))(this);
}

void Pl0000::ForceKill()
{
    ((void (__thiscall *)(Pl0000 *))(shared::base + 0x77CE20))(this);
}