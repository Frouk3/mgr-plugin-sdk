#include "PhaseManager.h"
#include "shared.h"

PhaseManager& g_PhaseManager = *(PhaseManager*)(shared::base + 0x14B9140);

int PhaseManager::GetCurrentPhase()
{
    return ((int (__cdecl *)())(shared::base + 0x532720))();
}

int PhaseManager::CreateReadRoomList(int a2, int a3, int a4)
{
    return ((int (__thiscall *)(PhaseManager *, int, int, int))(shared::base + 0x945560))(this, a2, a3, a4);
}

bool PhaseManager::IsCurrentPhase(const char* phase)
{
    return ((bool (__thiscall *)(PhaseManager *, const char *))(shared::base + 0x945560))(this, phase);
}

bool PhaseManager::IsDLCPhase()
{
    return ((bool (__thiscall *)(PhaseManager *))(shared::base + 0x9466F0))(this);
}

bool PhaseManager::IsSamDLC()
{
    return ((bool (__thiscall *)(PhaseManager *))(shared::base + 0x946780))(this);
}

bool PhaseManager::IsWolfDLC()
{
    return ((bool (__thiscall *)(PhaseManager *))(shared::base + 0x9467A0))(this);
}

int PhaseManager::SetDefaultData()
{
    return ((int (__thiscall *)(PhaseManager *))(shared::base + 0x94E890))(this);
}

bool PhaseManager::IsPassSubPhase(int a2, bool a3, const char *debugLog)
{
    return ((bool (__thiscall *)(PhaseManager *, int, bool , const char*))(shared::base + 0x94F0B0))(this, a2, a3, debugLog);
}

void PhaseManager::Startup()
{
    ((void (__thiscall *)(PhaseManager *))(shared::base + 0x958370))(this);
}

bool PhaseManager::SetSubPhaseData(const char* phase)
{
    return ((bool (__thiscall *)(PhaseManager *, const char *))(shared::base + 0x958D70))(this, phase);
}

bool PhaseManager::SetPhaseData(int a2)
{
    return ((bool (__thiscall *)(PhaseManager*, int))(shared::base + 0x95ED60))(this, a2);
}

void PhaseManager::GameOverEvent(int a2)
{
    ((void (__thiscall *)(PhaseManager *, int))(shared::base + 0x9664E0))(this, a2);
}