#pragma once

#include <shared.h>
#include <Collision.h>
#include <CollisionUserData.h>

namespace CollisionSystem
{
    inline CollisionCapsule* createCapsule(int type, int collisionFilter, CollisionUserData *userData)
    {
        return ((CollisionCapsule* (__cdecl *)(int, int, CollisionUserData *))(shared::base + 0x97DEA0))(type, collisionFilter, userData);
    }
    
    inline CollisionImpactWave *createImpactWave(int type, int collisionFilter, CollisionUserData *userData)
    {
        return ((CollisionImpactWave* (__cdecl *)(int, int, CollisionUserData *))(shared::base + 0x97DFE0))(type, collisionFilter, userData);
    }

    inline CollisionSphere *createSphere(int type, int collisionFilter, CollisionUserData *userData)
    {
        return ((CollisionSphere* (__cdecl *)(int, int, CollisionUserData *))(shared::base + 0x97DF90))(type, collisionFilter, userData);
    }
}