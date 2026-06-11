#pragma once

#include <Behavior.h>

class Et4010 : public Behavior
{
public:

    Et4010()
    {
        MAKE_CALL(shared::base + 0x6A6A80, void(__thiscall *)(Et4010 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17352C4);
};

VALIDATE_SIZE(Et4010, 0x870);