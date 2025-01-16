#pragma once

#include <hkpWorld.h>
#include <hkpEntity.h>

class hkpWorldPostSimulationListener
{
public:

    virtual ~hkpWorldPostSimulationListener() {};
    virtual void postSimulationCallback(const hkpWorld *world) {};
    virtual void inactiveEntityMovedCallback(const hkpEntity *entity) {};
};