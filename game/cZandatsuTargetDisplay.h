#pragma once

#include <Hw.h>
#include <cZandatsuTarget.h>

struct cZandatsuTargetDisplay
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    EntityHandle field_10;
    int field_14;
    Hw::CriticalSection field_18;
    int field_34;
    Hw::cFixedVector<cZandatsuTarget *> field_38;
    Hw::cFixedVector<EntityHandle> field_4C;
    int field_60[256];
    int field_460;
};