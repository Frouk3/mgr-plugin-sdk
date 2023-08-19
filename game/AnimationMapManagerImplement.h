#pragma once

#include "AnimationMapManager.h"
#include "Hw.h"
#include "lib.h"

struct AnimationMapResource
{
    
};

class AnimationMapManagerImplement : public AnimationMapManager
{
public:
    Hw::cHeapPhysical *m_pHeapPhysical;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    lib::AllocatedArray<AnimationMapResource *> *m_pAnimationMapResourceArray;
    int field_2C;

};