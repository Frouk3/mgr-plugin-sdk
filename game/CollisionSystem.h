#pragma once

#include <shared.h>
#include <Collision.h>
#include <CollisionUserData.h>

namespace CollisionSystem
{
    inline CollisionCapsule* createCapsule(int type, int collisionFilter, CollisionUserData *userData)
    {
        return MAKE_CALL(shared::base + 0x97DEA0, CollisionCapsule* (__cdecl *)(int, int, CollisionUserData *), type, collisionFilter, userData);
    }
    
    inline CollisionImpactWave *createImpactWave(int type, int collisionFilter, CollisionUserData *userData)
    {
        return MAKE_CALL(shared::base + 0x97DFE0, CollisionImpactWave* (__cdecl *)(int, int, CollisionUserData *), type, collisionFilter, userData);
    }

    inline CollisionSphere *createSphere(int type, int collisionFilter, CollisionUserData *userData)
    {
        return MAKE_CALL(shared::base + 0x97DF90, CollisionSphere* (__cdecl *)(int, int, CollisionUserData *), type, collisionFilter, userData);
    }
}