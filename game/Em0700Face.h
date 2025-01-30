#pragma once

#include <Behavior.h>

class Em0700Face : public Behavior
{
public:
    
    Em0700Face()
    {
        ((void(__thiscall *)(Em0700Face *))(shared::base + 0x6A66B0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17351C4);
};

VALIDATE_SIZE(Em0700Face, 0x870);