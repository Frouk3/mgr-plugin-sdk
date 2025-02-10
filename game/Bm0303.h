#pragma once

#include <Behavior.h>

class Bm0303 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    cEspControler field_880;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;

    Bm0303()
    {
        ((void(__thiscall *)(Bm0303*))(shared::base + 0x6A6E40))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BD0);
};

VALIDATE_SIZE(Bm0303, 0x950);