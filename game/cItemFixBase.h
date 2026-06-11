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
        MAKE_CALL(shared::base + 0x6B1420, void(__thiscall *)(cItemFixBase *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735394);
};

VALIDATE_SIZE(cItemFixBase, 0x930);