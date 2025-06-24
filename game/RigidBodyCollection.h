#pragma once

#include <HkPhysicsSystemContainer.h>

class RigidBodyCollection
{
public:
    HkPhysicsSystemContainer m_HkPhysicsSystemContainer;
    int field_10;
    int field_14;
    int field_18;

    virtual ContextInstance &getContext() {};
    virtual ~RigidBodyCollection() {};
};