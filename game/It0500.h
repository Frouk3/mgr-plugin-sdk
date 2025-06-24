#pragma once

#include <cItemViscelaBase.h>

class It0500 : public cItemViscelaBase
{
public:

    It0500()
    {
        ((void(__thiscall *)(It0500 *))(shared::base + 0x6C0D90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735380);
};

VALIDATE_SIZE(It0500, 0x970);