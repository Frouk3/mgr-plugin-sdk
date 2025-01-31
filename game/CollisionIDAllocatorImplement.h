#pragma once

#include <CollisionIDAllocator.h>
#include <Hw.h>
#include <lib.h>

class CollisionIDAllocatorImplement : public CollisionIDAllocator
{
public:
    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    int field_28;
    lib::StaticArray<unsigned int, 1024> *m_IDs;

    static inline CollisionIDAllocatorImplement * &ms_Instance = *(CollisionIDAllocatorImplement**)(shared::base + 0x19C52E4);
};

VALIDATE_SIZE(CollisionIDAllocatorImplement, 0x30);