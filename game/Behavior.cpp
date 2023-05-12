#include "Behavior.h"
#include "shared.h"

// structure constructor
Behavior::Behavior()
{
    ((void(__thiscall *)(Behavior *))(shared::base + 0x6A3540))(this);
}

void Behavior::Startup()
{
    CallVMTFunc<16, Behavior *>(this);
}

void Behavior::Function17()
{
    CallVMTFunc<17, Behavior *>(this);
}

void Behavior::Function18()
{
    CallVMTFunc<18, Behavior *>(this);
}

void Behavior::Update()
{
    CallVMTFunc<19, Behavior *>(this);
}

void Behavior::Function20()
{
    CallVMTFunc<20, Behavior *>(this);
}

void Behavior::Function21()
{
    CallVMTFunc<21, Behavior *>(this);
}

void Behavior::Function22()
{
    CallVMTFunc<22, Behavior *>(this);
}

void Behavior::Function23()
{
    CallVMTFunc<23, Behavior *>(this);
}

void Behavior::Function24()
{
    CallVMTFunc<24, Behavior *>(this);
}

void Behavior::Function25()
{
    CallVMTFunc<25, Behavior *>(this);
}

cVec4* Behavior::GetOffset()
{
    return CallVMTFunc<cVec4 *, 26, Behavior *>(this);
}

void Behavior::SetOffset(cVec4 *offset)
{
    CallVMTFunc<27, Behavior *, cVec4 *>(this, offset);
}

void Behavior::AddToOffset(cVec4* offset)
{
    CallVMTFunc<28, Behavior *, cVec4 *>(this, offset);
}

void Behavior::ChangeHeight(float height)
{
    CallVMTFunc<29, Behavior *, float>(this, height);
}

void Behavior::Place(cVec4 *pos, cVec4* rotation)
{
    CallVMTFunc<30, Behavior *, cVec4 *, cVec4 *>(this, pos, rotation);
}

void Behavior::Place(cVec4 *pos, cVec4* rotation, cVec4* size)
{
    CallVMTFunc<31, Behavior *, cVec4 *, cVec4 *, cVec4 *>(this, pos, rotation, size);
}

void Behavior::Function32()
{
    CallVMTFunc<32, Behavior *>(this);
}

cVec4 *Behavior::GetRotation()
{
    return CallVMTFunc<cVec4 *, 33, Behavior *>(this);
}

void Behavior::SetRotation(cVec4 *rotation)
{
    CallVMTFunc<34, Behavior *, cVec4 *>(this, rotation);
}

cVec4* Behavior::GetSize()
{
    return CallVMTFunc<cVec4 *, 35, Behavior *>(this);
}

void Behavior::SetSize(cVec4 *size)
{
    CallVMTFunc<36, Behavior *, cVec4 *>(this, size);
}

int Behavior::Function37()
{
    return CallVMTFunc<int, 37, Behavior *>(this);
}

int Behavior::GetIndex()
{
    return CallVMTFunc<int, 38, Behavior *>(this);
}

void Behavior::Transform(D3DXMATRIX *matrix)
{
    CallVMTFunc<45, Behavior *, D3DXMATRIX *>(this, matrix);
}

void Behavior::Inverse(D3DXMATRIX *matrix)
{
    CallVMTFunc<46, Behavior *, D3DXMATRIX *>(this, matrix);
}

cVec4 Behavior::GetOffsetPosition()
{
    return CallVMTFunc<cVec4, 159, Behavior *>(this);
}

void Behavior::SetSeqAtk()
{
    CallVMTFunc<74, Behavior *>(this);
}

void Behavior::SetState(int action, int id, int prevAct, int prevId)
{
    ((void (__thiscall *)(Behavior *, int, int, int, int))(shared::base + 0x68CAF0))(this, action, id, prevAct, prevId);
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
    CallVMTFunc<68, Behavior *, bool>(this, bEnable);
}

// @param a2 Unknown
bool Behavior::SetupCloth(int a2)
{
    return ((bool (__thiscall *)(Behavior *, int))(shared::base + 0x692380))(this, a2);
}