#pragma once

#include <Behavior.h>

class CodecModelObj : public Behavior
{
public:

    CodecModelObj()
    {
        ((void(__thiscall *)(CodecModelObj *))(shared::base + 0x6A6D90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735430);
};

VALIDATE_SIZE(CodecModelObj, 0x870);