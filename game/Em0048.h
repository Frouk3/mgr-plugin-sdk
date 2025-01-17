#pragma once

#include <Behavior.h>

class Em0048 : public Behavior
{
public:

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735428);
};

VALIDATE_SIZE(Em0048, 0x870);