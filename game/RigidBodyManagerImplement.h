#pragma once

#include <RigidBodyManager.h>
#include <Hw.h>
#include <lib.h>
#include <hkpRigidBody.h>

class RigidBodyManagerImplement : public RigidBodyManager
{
public:
    struct Work
    {
        hkpRigidBody *m_RigidBody;
        int field_4;
    };

    int field_4;
    int field_8;
    int field_C;
    Hw::cHeapFixed m_FixedHeap;
    lib::AllocatedArray<Work*> *m_RigidBodyWorks;
    int field_6C;
    Hw::CriticalSection field_70;
    int field_94;

    static inline RigidBodyManagerImplement *& ms_Instance = *(RigidBodyManagerImplement**)(shared::base + 0x1735F9C);
};

VALIDATE_SIZE(RigidBodyManagerImplement, 0x98);