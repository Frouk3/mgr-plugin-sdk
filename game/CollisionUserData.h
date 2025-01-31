#pragma once

#include <common.h>

class CollisionUserData
{
public:
    int field_4;

    virtual ContextInstance& getContext() { static ContextInstance context; return context; }; // will be overriden by constructor
    virtual ~CollisionUserData() {};
};