#include "SceneModelSystem.h"
#include "shared.h"

SceneModelSystem::SceneModelSystem()
{
    ((void (__thiscall *)(SceneModelSystem *))(shared::base + 0x6197D0))(this);
}

// unused
void SceneModelSystem::DestroyModel(int a2)
{
    ((void (__thiscall *)(SceneModelSystem *, int))(shared::base + 0x60C9F0))(this, a2);
}
// unused
void SceneModelSystem::CreateModel(int a2, int a3, int a4)
{
    ((void (__thiscall *)(SceneModelSystem *, int, int, int))(shared::base + 0x60C9A0))(this, a2, a3, a4);
}