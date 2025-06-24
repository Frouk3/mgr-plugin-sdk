#pragma once

#include <hkBase.h>

class hkMemoryAllocator
{
private:
    virtual void dummyVM() {};
public:

    struct MemoryStatistics
    {
        hkLong m_allocated;
        hkLong m_inUse;
        hkLong m_peakInUse;
        hkLong m_available;
        hkLong m_totalAvailable;
        hkLong m_largestBlock;
    };
};