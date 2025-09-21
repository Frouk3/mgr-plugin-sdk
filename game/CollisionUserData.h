#pragma once

#include <common.h>

class CollisionUserData
{
public:
    struct HitData {};
public:
    int field_4;
    HitData *m_pHitData;

    virtual ContextInstance& getContext() { return *(ContextInstance*)(shared::base + 0x19C52FC); }; // will be overriden by constructor
    virtual ~CollisionUserData() {};
};