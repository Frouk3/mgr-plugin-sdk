#pragma once

#include <BehaviorBm.h>

class Bm0201 : public BehaviorBm
{
public:

    Bm0201()
    {
        ((void(__thiscall *)(Bm0201 *))(shared::base + 0x6B0160))(this);
    }
    
    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B98);
};

VALIDATE_SIZE(Bm0201, 0xB40);