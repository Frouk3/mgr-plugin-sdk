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

cVec4 *Entity::GetOffset()
{
    return ((cVec4 *(__thiscall *)(Entity *))(shared::base + 0x67C8B0))(this);
}

void Entity::SetOffset(cVec4 *offset)
{
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CE90))(this, offset);
}

void Entity::AddToOffset(cVec4 *offset)
{
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CEC0))(this, offset);
}

void Entity::SetRotation(cVec4 *rotation)
{
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CF00))(this, rotation);
}

void Entity::SetSize(cVec4 *size)
{
    ((void (__thiscall *)(Entity *, cVec4 *))(shared::base + 0x67CF90))(this, size);
}

cVec4* Entity::GetRotation()
{
    return ((cVec4 *(__thiscall *)(Entity *))(shared::base + 0x67C8D0))(this);
}

cVec4 *Entity::GetSize()
{
    return ((cVec4 *(__thiscall *)(Entity *))(shared::base + 0x67C8F0))(this);
}