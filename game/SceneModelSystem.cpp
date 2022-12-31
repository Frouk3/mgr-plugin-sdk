#include "SceneModelSystem.h"
#include "shared.h"

SceneModelSystem::SceneModelSystem() noexcept
{
    DWORD address = shared::base + 0x6197D0;
    ((void (__thiscall *)(SceneModelSystem *))address)(this);
}

SceneModelSystem::~SceneModelSystem() noexcept
{
    DWORD address = shared::base + 0x619710;
    ((void (__thiscall *)(SceneModelSystem *))address)(this);
}

void SceneModelSystem::DestroyModel(int a2) noexcept
{
    DWORD address = shared::base + 0x60C9F0;
    ((void (__thiscall *)(SceneModelSystem *, int))address)(this, a2);
}

void SceneModelSystem::CreateModel(int a2, int a3, int a4) noexcept
{
    DWORD address = shared::base + 0x60C9A0;
    ((void (__thiscall *)(SceneModelSystem *, int, int, int))address)(this, a2, a3, a4);
}