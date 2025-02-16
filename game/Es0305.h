#pragma once

#include <BehaviorAppBase.h>

class Es0305 : public BehaviorAppBase
{
public:

    Es0305()
    {
        ((void(__thiscall *)(Es0305 *))(shared::base + 0x6AC100))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735204);
};

VALIDATE_SIZE(Es0305, 0xA00);