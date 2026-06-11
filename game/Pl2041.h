#pragma once

#include <Behavior.h>

class Pl2041 : public Behavior
{
public:

    Pl2041()
    {
        MAKE_CALL(shared::base + 0x6A6ED0, void (__thiscall *)(Pl2041*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735424);
};

VALIDATE_SIZE(Pl2041, 0x870);