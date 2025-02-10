#pragma once

#include <BehaviorBh.h>

class Bh0016 : public BehaviorBh
{
public:

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B64);
};