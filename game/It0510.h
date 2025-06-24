#pragma once

#include <cItemViscelaBase.h>

class It0510 : public cItemViscelaBase
{
public:

    It0510()
    {
        ((void(__thiscall *)(It0510 *))(shared::base + 0x6C0E10))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735384);
};

VALIDATE_SIZE(It0510, 0x970);