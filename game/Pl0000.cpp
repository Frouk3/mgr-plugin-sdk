#include "shared.h"
#include "Pl0000.h"

Pl0000::Pl0000()
{
    ((void (__thiscall *)(Pl0000 *))(shared::base + 0x6C0310))(this);
}

bool Pl0000::IsBladeModeActive()
{
    return ReturnCallVMTFunc<bool, 203, Pl0000 *>(this);
}

bool Pl0000::IsRunning()
{
    return ReturnCallVMTFunc<bool, 204, Pl0000 *>(this);
}

bool Pl0000::IsIdle()
{
    return ReturnCallVMTFunc<bool, 206, Pl0000 *>(this);
}

bool Pl0000::IsInAir()
{
    return ReturnCallVMTFunc<bool, 208, Pl0000 *>(this);
}

bool Pl0000::CanActivateRipperMode()
{
    return ReturnCallVMTFunc<bool, 209, Pl0000 *>(this);
}

bool Pl0000::IsCodecTalk()
{
    return ReturnCallVMTFunc<bool, 211, Pl0000 *>(this);
}

bool Pl0000::IsParrying()
{
    return ReturnCallVMTFunc<bool, 216, Pl0000 *>(this);
}

bool Pl0000::IsOnGround()
{
    return ReturnCallVMTFunc<bool, 220, Pl0000 *>(this);
}

void Pl0000::ForceKill()
{
    CallVMTFunc<227, Pl0000 *>(this);
}

float Pl0000::GetDefenseDamage()
{
    return ReturnCallVMTFunc<float, 237, Pl0000 *>(this);
}

void Pl0000::UpdateInput()
{
    CallVMTFunc<241, Pl0000 *>(this);
}

void Pl0000::HandleActions()
{
    CallVMTFunc<242, Pl0000 *>(this);
}

void Pl0000::ChangeSubWeapon()
{
    CallVMTFunc<246, Pl0000 *>(this);
}

// duplicate at field_3DC(247th virtual function)
void Pl0000::CreateEffect(int id, cEspControler *esp)
{
    CallVMTFunc<248, Pl0000 *, int, cEspControler *>(this, id, esp);
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

int Pl0000::GetMaxHealth()
{
    return ((int(__thiscall *)(Pl0000 *))(shared::base + 0x77C980))(this);
}
