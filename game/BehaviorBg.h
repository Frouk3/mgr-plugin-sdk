#pragma once

#include "BehaviorBgBase.h"

class BehaviorBg : public BehaviorBgBase
{
public:

    static inline ContextInstance& Context = *(ContextInstance*)(shared::base + 0x17E9C50);
};