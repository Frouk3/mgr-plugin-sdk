#pragma once

#include <BehaviorBm.h>

class Bm0201 : public BehaviorBm
{
public:

    Bm0201()
    {
        MAKE_CALL(shared::base + 0x6B0160, void(__thiscall *)(Bm0201 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B98);
};

VALIDATE_SIZE(Bm0201, 0xB40);