#pragma once

#include <cItemViscelaBase.h>

class It0500 : public cItemViscelaBase
{
public:

    It0500()
    {
        MAKE_CALL(shared::base + 0x6C0D90, void(__thiscall *)(It0500 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735380);
};

VALIDATE_SIZE(It0500, 0x970);