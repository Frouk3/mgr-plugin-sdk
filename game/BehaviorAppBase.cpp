#include "BehaviorAppBase.h"
#include "shared.h"

BehaviorAppBase::BehaviorAppBase()
{
    // empty constructor, since we don't have full constructor for this
}

void BehaviorAppBase::Heal(int heal)
{
    CallVMTFunc<194, BehaviorAppBase *, int>(this, heal);
}

void BehaviorAppBase::SetupHealth(int health)
{
    ((void(__thiscall *)(BehaviorAppBase *, int))(shared::base + 0x68EDF0))(this, health);
}

void BehaviorAppBase::Damage(int damage, bool leave1Hp)
{
    CallVMTFunc<195, BehaviorAppBase *, int, bool>(this, damage, leave1Hp);
}