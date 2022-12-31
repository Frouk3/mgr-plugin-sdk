#include "cObj.h"
#include "shared.h"

cObj::cObj() noexcept
{
    DWORD address = shared::base + 0x5FD150;
    ((void (__thiscall *)(cObj *))address)(this);
}

cObj::~cObj() noexcept
{
    DWORD address = shared::base + 0x5F88E0;
    ((void (__thiscall *)(cObj *))address)(this);
}

void cObj::EnableRender() noexcept
{
    DWORD address = shared::base + 0x5FABA0;
    ((void (__thiscall *)(cObj *))address)(this);
}

void cObj::DisableRender() noexcept
{
    DWORD address = shared::base + 0x5FABA0;
    ((void (__thiscall *)(cObj *))address)(this);
}