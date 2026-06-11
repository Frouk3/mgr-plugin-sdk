#pragma once

#include <BehaviorBm.h>

class Bm1010 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm1010()
    {
        MAKE_CALL(shared::base + 0x6B0770, void(__thiscall *)(Bm1010 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734BEC);
};

VALIDATE_SIZE(Bm1010, 0xB50);