#include "Entity.h"
#include "shared.h"

void *Entity::GetItemInstance()
{
    return ((void *(__thiscall *)(Entity *))(shared::base + 0x67C8A0))(this);
}

void Entity::UpdateSlowRateUnit()
{
    ((void (__thiscall *)(Entity *))(shared::base + 0xA049A0))(this);
}

float Entity::GetCalculatedSlowRate()
{
    return ((float (__thiscall *)(Entity *))(shared::base + 0xA049B0))(this);
}

void Entity::SetEntitySlowRateType(int SlowRateType)
{
    ((void (__thiscall *)(Entity *, int))(shared::base + 0xA08640))(this, SlowRateType);
}