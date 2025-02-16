#pragma once

#include <DebrisManager.h>
#include <Hw.h>
#include <lib.h>
#include <Entity.h>

class DebrisManagerImplement : public DebrisManager
{
public:
    struct DebrisHandle
    {
        EntityHandle m_Entity;
        float m_fLifetime;
    };

    Hw::cHeapVariable *m_Allocator;
    lib::AllocatedArray<Entity*> *m_DebrisEntities;
    Hw::cFixedVector<DebrisHandle> m_DebrisHandles;
    Hw::CriticalSection field_20;
    int field_3C;

    static inline DebrisManagerImplement * &ms_Instance = *(DebrisManagerImplement**)(shared::base + 0x17EA18C);
};

VALIDATE_SIZE(DebrisManagerImplement, 0x40);