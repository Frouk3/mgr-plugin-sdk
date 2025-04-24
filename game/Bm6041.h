#pragma once

#include <BehaviorBm.h>

class Bm6041 : public BehaviorBm
{
public:

    Bm6041()
    {
        ((void(__thiscall *)(Bm6041 *))(shared::base + 0x6B1740))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354F4);
};

VALIDATE_SIZE(Bm6041, 0xB40);