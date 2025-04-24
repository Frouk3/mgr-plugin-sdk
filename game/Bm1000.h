#pragma once

#include <BehaviorBm.h>

class Bm1000 : public BehaviorBm
{
public:

    Bm1000()
    {
        ((void(__thiscall *)(Bm1000 *))(shared::base + 0x6B0320))(this);
    }
    
    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BE8);
};

VALIDATE_SIZE(Bm1000, 0xB40);