#include "BehaviorAppBase.h"
#include "shared.h"

BehaviorAppBase::BehaviorAppBase()
{
    // empty constructor, since we don't have full constructor for this
}

void BehaviorAppBase::Startup()
{
    ((void(__thiscall *)(BehaviorAppBase *))(shared::base + 0x698340))(this);
}

void BehaviorAppBase::Heal(int heal)
{
    ((void(__thiscall *)(BehaviorAppBase *, int))(shared::base + 0x68EE70))(this, heal);
}

void BehaviorAppBase::SetupHealth(int health)
{
    ((void(__thiscall *)(BehaviorAppBase *, int))(shared::base + 0x68EDF0))(this, health);
}

void BehaviorAppBase::Damage(int damage, bool leave1Hp)
{
    ((void(__thiscall *)(BehaviorAppBase *, int, bool))(shared::base + 0x68EE30))(this, damage, leave1Hp);
}