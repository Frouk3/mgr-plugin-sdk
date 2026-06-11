#pragma once

#include <CriBase.h>
#include <shared.h>

inline int CRIAPI criAtomic_TestAndSet(LONG* target, LONG value)
{
    return MAKE_CALL(shared::base + 0x10998F9, int(CRIAPI *)(LONG *, LONG), target, value);
}