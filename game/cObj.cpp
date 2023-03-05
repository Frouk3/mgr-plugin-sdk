#include "cObj.h"
#include "shared.h"

cObj::cObj()
{
    ((void (__thiscall *)(cObj *))(shared::base + 0x5FD150))(this);
}

void cObj::EnableRender()
{
    ((void (__thiscall *)(cObj *))(shared::base + 0x5FABA0))(this);
}

void cObj::DisableRender()
{
    ((void (__thiscall *)(cObj *))(shared::base + 0x5FABA0))(this);
}