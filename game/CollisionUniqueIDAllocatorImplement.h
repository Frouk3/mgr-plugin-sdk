#pragma once

#include <CollisionUniqueIDAllocator.h>
#include <Hw.h>

class CollisionUniqueIDAllocatorImplement : public CollisionUniqueIDAllocator
{
public:
    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    int field_28;
    int field_2C;
};