#pragma once

#include <BehaviorBm.h>

class Bm6041 : public BehaviorBm
{
public:

    Bm6041()
    {
        MAKE_CALL(shared::base + 0x6B1740, void(__thiscall *)(Bm6041 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17354F4);
};

VALIDATE_SIZE(Bm6041, 0xB40);