#include "PhaseManager.h"
#include "shared.h"

PhaseManager& g_PhaseManager = *(PhaseManager*)(shared::base + 0x14B9140);

int PhaseManager::GetCurrentPhase() noexcept
{
    DWORD address = shared::base + 0x532720;
    return ((int (__cdecl *)())address)();
}

int PhaseManager::CreateReadRoomList(int a2, int a3, int a4) noexcept
{
    DWORD address = shared::base + 0x945560;
    return ((int (__thiscall *)(PhaseManager *, int, int, int))address)(this, a2, a3, a4);
}

bool PhaseManager::IsCurrentPhase(const char* phase) noexcept
{
    DWORD address = shared::base + 0x945560;
    return ((bool (__thiscall *)(PhaseManager *, const char *))address)(this, phase);
}

bool PhaseManager::IsDLCPhase() noexcept
{
    DWORD address = shared::base + 0x9466F0;
    return ((bool (__thiscall *)(PhaseManager *))address)(this);
}

bool PhaseManager::IsSamDLC() noexcept
{
    DWORD address = shared::base + 0x946780;
    return ((bool (__thiscall *)(PhaseManager *))address)(this);
}

bool PhaseManager::IsWolfDLC() noexcept
{
    DWORD address = shared::base + 0x9467A0;
    return ((bool (__thiscall *)(PhaseManager *))address)(this);
}

int PhaseManager::SetDefaultData() noexcept
{
    DWORD address = shared::base + 0x94E890;
    return ((int (__thiscall *)(PhaseManager *))address)(this);
}

bool PhaseManager::IsPassSubPhase(int a2, bool a3, const char *debugLog) noexcept
{
    DWORD address = shared::base + 0x94F0B0;
    return ((bool (__thiscall *)(PhaseManager *, int, bool , const char*))address)(this, a2, a3, debugLog);
}

void PhaseManager::Startup() noexcept
{
    DWORD address = shared::base + 0x958370;
    ((void (__thiscall *)(PhaseManager *))address)(this);
}

bool PhaseManager::SetSubPhaseData(const char* phase) noexcept
{
    DWORD address = shared::base + 0x958D70;
    return ((bool (__thiscall *)(PhaseManager *, const char *))address)(this, phase);
}

bool PhaseManager::SetPhaseData(int a2) noexcept
{
    DWORD address = shared::base + 0x95ED60;
    return ((bool (__thiscall *)(PhaseManager*, int))address)(this, a2);
}

void PhaseManager::GameOverEvent(int a2) noexcept
{
    DWORD address = shared::base + 0x9664E0;
    ((void (__thiscall *)(PhaseManager *, int))address)(this, a2);
}