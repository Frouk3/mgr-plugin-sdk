#pragma once

#include <cItemObjectBase.h>

class cItemViscelaBase : public cItemObjectBase
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
    Hw::cTexture field_948;
    int field_964;
    int field_968;
    int field_96C;

    cItemViscelaBase()
    {
        ((void(__thiscall *)(cItemViscelaBase*))(shared::base + 0x6B6700))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17353C0);
};

VALIDATE_SIZE(cItemViscelaBase, 0x970);