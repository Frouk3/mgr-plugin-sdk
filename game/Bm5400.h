#pragma once

#include <P458AtqScr.h>

class Bm5400 : public P458AtqScr
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
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;

    Bm5400()
    {
        ((void(__thiscall *)(Bm5400 *))(shared::base + 0x6C1120))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BF0);
};

VALIDATE_SIZE(Bm5400, 0xB70);