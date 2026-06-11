#pragma once

#include <BehaviorAppBase.h>

class Es0305 : public BehaviorAppBase
{
public:

    Es0305()
    {
        MAKE_CALL(shared::base + 0x6AC100, void(__thiscall *)(Es0305 *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x1735204);
};

VALIDATE_SIZE(Es0305, 0xA00);