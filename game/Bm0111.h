#pragma once

#include <BehaviorBm.h>

class Bm0111 : public BehaviorBm
{
public:

    Bm0111()
    {
        MAKE_CALL(shared::base + 0x6B01B0, void(__thiscall *)(Bm0111 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B80);
};

VALIDATE_SIZE(Bm0111, 0xB40);