#pragma once

#include <BehaviorBm.h>

class Bm0423 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;

    Bm0423()
    {
        MAKE_CALL(shared::base + 0x6B0820, void(__thiscall *)(Bm0423 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734BDC);
};

VALIDATE_SIZE(Bm0423, 0xB60);