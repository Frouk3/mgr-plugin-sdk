#pragma once

#include <CriBase.h>
#include <shared.h>

inline int CRIAPI criAtomic_TestAndSet(LONG* target, LONG value)
{
    return ((int(CRIAPI*)(LONG*, LONG))(shared::base + 0x10998F9))(target, value);
}