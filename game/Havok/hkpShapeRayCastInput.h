#pragma once

#include <hkBase.h>
#include <hkpCollidable.h>

class hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkUint32 m_filterInfo;
    const hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter;
    const hkpCollidable *m_collidable;
    hkUlong m_userData;
};