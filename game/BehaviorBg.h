#pragma once

#include "BehaviorBgBase.h"

class BehaviorBg : public BehaviorBgBase
{
public:

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C50);
};