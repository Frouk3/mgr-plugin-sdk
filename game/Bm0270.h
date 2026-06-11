#pragma once

#include <BehaviorBm.h>

class Bm0270 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    Bm0270()
    {
        MAKE_CALL(shared::base + 0x6B0990, void(__thiscall *)(Bm0270 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734BB0);
};

VALIDATE_SIZE(Bm0270, 0xB50);