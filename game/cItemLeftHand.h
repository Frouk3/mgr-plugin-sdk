#pragma once

#include <cItemObjectBase.h>

class cItemLeftHand : public cItemObjectBase
{
public:
    int field_920;
    int field_924;
    int field_928;
    int field_92C;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;

    cItemLeftHand()
    {
        ((void(__thiscall *)(cItemLeftHand *))(shared::base + 0x6B13C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17353B0);
};

VALIDATE_SIZE(cItemLeftHand, 0x950);