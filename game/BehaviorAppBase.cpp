#include "BehaviorAppBase.h"
#include "shared.h"

void BehaviorAppBase::Startup() noexcept
{
    DWORD address = shared::base + 0x698340;
    ((void(__thiscall *)(BehaviorAppBase *))address)(this);
}

void BehaviorAppBase::Heal(int heal) noexcept
{
    DWORD address = shared::base + 0x68EE70;
    ((void(__thiscall *)(BehaviorAppBase *, int))address)(this, heal);
}

void BehaviorAppBase::SetupHealth(int health) noexcept
{
    DWORD address = shared::base + 0x68EDF0;
    ((void(__thiscall *)(BehaviorAppBase *, int))address)(this, health);
}

void BehaviorAppBase::Damage(int damage, bool leave1Hp) noexcept
{
    DWORD address = shared::base + 0x68EE30;
    ((void(__thiscall *)(BehaviorAppBase *, int, bool))address)(this, damage, leave1Hp);
}