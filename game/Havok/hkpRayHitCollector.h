#pragma once

#include <hkBase.h>
struct hkpShapeRayCastInput;
struct hkpShapeRayCastCollectorOutput;

class hkpCdBody;

class hkpRayHitCollector
{
public:
    float m_earlyOutDistance;

    virtual void addRayHit(hkpCdBody const& cdPoint, hkpShapeRayCastCollectorOutput const& hitInfo) {};
    virtual ~hkpRayHitCollector() {};
};