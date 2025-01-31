#pragma once

#include <hkMemoryAllocator.h>

class hkLifoAllocator : public hkMemoryAllocator
{
public:
    struct Implementation
    {

    };

    Implementation *m_impl;
    const int m_slabSize;
    void *m_cur;
    void *m_end;
    void *m_firstNonLifoEnd;
    void *m_cachedEmptySlab;
    hkMemoryAllocator *m_slabAllocator;
    hkMemoryAllocator *m_largeAllocator;
    hkMemoryAllocator *m_internalAllocator;
};