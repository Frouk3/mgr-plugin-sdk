#pragma once

#include <hkBase.h>

struct hkpCdPoint;

class hkpCdPointCollector
{
public:
    hkReal m_earlyOutDistance;

    virtual ~hkpCdPointCollector() {};
    virtual void addCdPoint(const hkpCdPoint &point) {};
    virtual void reset() {};
};