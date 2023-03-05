#include "EntityHandle.h"
#include "shared.h"

void *EntityHandle::GetItemInstance()
{
    return ((void *(__thiscall *)(EntityHandle *))(shared::base + 0x67C8A0))(this);
}

void EntityHandle::UpdateSlowRateUnit()
{
    ((void (__thiscall *)(EntityHandle *))(shared::base + 0xA049A0))(this);
}

float EntityHandle::GetCalculatedSlowRate()
{
    return ((float (__thiscall *)(EntityHandle *))(shared::base + 0xA049B0))(this);
}

void EntityHandle::SetEntitySlowRateType(int SlowRateType)
{
    ((void (__thiscall *)(EntityHandle *, int))(shared::base + 0xA08640))(this, SlowRateType);
}