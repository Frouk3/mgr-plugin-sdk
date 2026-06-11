#pragma once

#include <Behavior.h>

class CodecModelObj : public Behavior
{
public:

    CodecModelObj()
    {
        MAKE_CALL(shared::base + 0x6A6D90, void(__thiscall *)(CodecModelObj *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735430);
};

VALIDATE_SIZE(CodecModelObj, 0x870);