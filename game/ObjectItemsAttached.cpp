#include "ObjectItemsAttached.h"
#include "../shared/shared.h"

void *ObjectItemsAttached::GetItemInstance() noexcept
{
    DWORD address = shared::base + 0x67C8A0;
    return ((void *(__thiscall *)(ObjectItemsAttached *))address)(this);
}

void ObjectItemsAttached::UpdateSlowRateUnit() noexcept
{
    DWORD address = shared::base + 0xA049A0;
    ((void (__thiscall *)(ObjectItemsAttached *))address)(this);
}

float ObjectItemsAttached::GetCalculatedSlowRate() noexcept
{
    DWORD address = shared::base + 0xA049B0;
    return ((float (__thiscall *)(ObjectItemsAttached *))address)(this);
}

void ObjectItemsAttached::SetEntitySlowRateType(int SlowRateType) noexcept
{
    DWORD address = shared::base + 0xA08640;
    ((void (__thiscall *)(ObjectItemsAttached *, int))address)(this, SlowRateType);
}