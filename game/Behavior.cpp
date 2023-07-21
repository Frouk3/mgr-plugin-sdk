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

void Behavior::Tick()
{
    CallVMTFunc<19, Behavior *>(this);
}

void Behavior::Function20()
{
    CallVMTFunc<20, Behavior *>(this);
}

void Behavior::UpdateBodyParts()
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
    return ReturnCallVMTFunc<cVec4 *, 26, Behavior *>(this);
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
    return ReturnCallVMTFunc<cVec4 *, 33, Behavior *>(this);
}

void Behavior::SetRotation(cVec4 *rotation)
{
    CallVMTFunc<34, Behavior *, cVec4 *>(this, rotation);
}

cVec4* Behavior::GetSize()
{
    return ReturnCallVMTFunc<cVec4 *, 35, Behavior *>(this);
}

void Behavior::SetSize(cVec4 *size)
{
    CallVMTFunc<36, Behavior *, cVec4 *>(this, size);
}

int Behavior::GetSequence()
{
    return ReturnCallVMTFunc<int, 37, Behavior *>(this);
}

int Behavior::GetIndex()
{
    return ReturnCallVMTFunc<int, 38, Behavior *>(this);
}

int Behavior::GetSequenceFile(const char *a2)
{
    return ReturnCallVMTFunc<int, 39, Behavior *>(this);
}

int Behavior::Function40()
{
    return ReturnCallVMTFunc<int, 40, Behavior *>(this);
}

void Behavior::Function41()
{
    CallVMTFunc<41, Behavior *>(this);
}

int Behavior::Function42()
{
    return ReturnCallVMTFunc<int, 42, Behavior *>(this);
}

void Behavior::Transform(D3DXMATRIX *matrix)
{
    CallVMTFunc<45, Behavior *, D3DXMATRIX *>(this, matrix);
}

void Behavior::Inverse(D3DXMATRIX *matrix)
{
    CallVMTFunc<46, Behavior *, D3DXMATRIX *>(this, matrix);
}

void Behavior::SetStealthCamoEnabled(bool bEnable)
{
    CallVMTFunc<68, Behavior *, bool>(this, bEnable);
}

void Behavior::SetSeqAtk()
{
    CallVMTFunc<74, Behavior *>(this);
}

void *Behavior::SetCutCreateInfo()
{
    return ReturnCallVMTFunc<void *, 110, Behavior *>(this);
}

bool Behavior::IsAlive()
{
    return ReturnCallVMTFunc<bool, 128, Behavior *>(this);
}

cVec4 Behavior::GetOffsetPosition()
{
    return ReturnCallVMTFunc<cVec4, 159, Behavior *>(this);
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

// @param a2 Unknown
bool Behavior::SetupCloth(int a2)
{
    return ((bool (__thiscall *)(Behavior *, int))(shared::base + 0x692380))(this, a2);
}