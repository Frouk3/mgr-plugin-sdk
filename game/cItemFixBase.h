#pragma once

#include <cItemObjectBase.h>

class cItemFixBase : public cItemObjectBase
{
public:
    int field_920;
    int field_924;
    int field_928;
    int field_92C;

    cItemFixBase()
    {
        ((void(__thiscall *)(cItemFixBase *))(shared::base + 0x6B1420))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735394);
};

VALIDATE_SIZE(cItemFixBase, 0x930);