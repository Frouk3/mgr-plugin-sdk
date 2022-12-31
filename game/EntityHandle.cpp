#include "EntityHandle.h"
#include "shared.h"

void *EntityHandle::GetItemInstance() noexcept
{
    DWORD address = shared::base + 0x67C8A0;
    return ((void *(__thiscall *)(EntityHandle *))address)(this);
}

void EntityHandle::UpdateSlowRateUnit() noexcept
{
    DWORD address = shared::base + 0xA049A0;
    ((void (__thiscall *)(EntityHandle *))address)(this);
}

float EntityHandle::GetCalculatedSlowRate() noexcept
{
    DWORD address = shared::base + 0xA049B0;
    return ((float (__thiscall *)(EntityHandle *))address)(this);
}

void EntityHandle::SetEntitySlowRateType(int SlowRateType) noexcept
{
    DWORD address = shared::base + 0xA08640;
    ((void (__thiscall *)(EntityHandle *, int))address)(this, SlowRateType);
}