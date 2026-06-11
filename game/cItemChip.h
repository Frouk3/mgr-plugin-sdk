#pragma once

#include <cItemObjectBase.h>

class cItemChip : public cItemObjectBase
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
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    int field_960;
    int field_964;
    int field_968;
    int field_96C;

    cItemChip()
    {
        MAKE_CALL(shared::base + 0x6B1490, void(__thiscall *)(cItemChip*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x173539C);
};

VALIDATE_SIZE(cItemChip, 0x970);
