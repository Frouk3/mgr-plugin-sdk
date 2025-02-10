#pragma once

#include <cItemObjectBase.h>

class cItemBox : public cItemObjectBase
{
public:
    int field_920;
    int field_924;
    int field_928;
    int field_92C;

    cItemBox()
    {
        ((void(__thiscall *)(cItemBox *))(shared::base + 0x6B1360))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735398);
};

VALIDATE_SIZE(cItemBox, 0x930);