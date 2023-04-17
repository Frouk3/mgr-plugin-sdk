#include "Behavior.h"
#include "shared.h"

// structure constructor
Behavior::Behavior()
{
    ((void(__thiscall *)(Behavior *))(shared::base + 0x6A3540))(this);
}

void Behavior::Startup()
{
    ((void(__thiscall *)(Behavior *))(shared::base + 0x691E90))(this);
}

cVec4 Behavior::GetOffsetPosition()
{
    return ((cVec4 (__thiscall *)(Behavior *))(shared::base + 0x00DE30))(this);
}

void Behavior::SetState(int a1, int a2, int a3, int a4)
{
    ((void (__thiscall *)(Behavior *, int, int, int, int))(shared::base + 0x68CAF0))(this, a1, a2, a3, a4);
}

int Behavior::GetCurrentActionId()
{
    return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAC0))(this);
}

int Behavior::GetCurrentAction()
{
    return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAB0))(this);
}

void Behavior::SetStealthCamoEnabled(bool bEnable)
{
    ((void (__thiscall *)(Behavior *, bool))(shared::base + 0x68E710))(this, bEnable);
}

// @param a2 Unknown
bool Behavior::SetupCloth(int a2)
{
    return ((bool (__thiscall *)(Behavior *, int))(shared::base + 0x692380))(this, a2);
}

cVec4 *Behavior::GetOffset()
{
    return ((cVec4 *(__thiscall *)(Behavior *))(shared::base + 0x692780))(this);
}

void Behavior::SetOffset(cVec4 *offset)
{
    ((void (__thiscall *)(Behavior *, cVec4 *))(shared::base + 0x6927A0))(this, offset);
}

void Behavior::AddToOffset(cVec4* offset)
{
    ((void (__thiscall *)(Behavior *, cVec4 *))(shared::base + 0x6927C0))(this, offset);
}

void Behavior::ChangeHeight(float height)
{
    ((void (__thiscall *)(Behavior *, float))(shared::base + 0x6927E0))(this, height);
}

void Behavior::Place(cVec4 *pos, cVec4* rotation)
{
    ((void (__thiscall *)(Behavior *, cVec4 *, cVec4 *))(shared::base + 0x692820))(this, pos, rotation);
}

void Behavior::Place(cVec4 *pos, cVec4* rotation, cVec4* size)
{
    ((void (__thiscall *)(Behavior *, cVec4 *, cVec4 *, cVec4 *))(shared::base + 0x6928B0))(this, pos, rotation, size);
}

cVec4 *Behavior::GetRotation()
{
    return ((cVec4* (__thiscall *)(Behavior *))(shared::base + 0x692950))(this);
}

void Behavior::SetRotation(cVec4 *rotation)
{
    ((void (__thiscall *)(Behavior *, cVec4 *))(shared::base + 0x692970))(this, rotation);
}

void Behavior::SetSize(cVec4 *size)
{
    ((void (__thiscall *)(Behavior *, cVec4 *))(shared::base + 0x6929B0))(this, size);
}

cVec4* Behavior::GetSize()
{
    return ((cVec4 *(__thiscall *)(Behavior *))(shared::base + 0x692990))(this);
}