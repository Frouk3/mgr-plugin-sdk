#pragma once

#include <hkBase.h>
#include <hkpCollidable.h>
#include <hkFourTransposedPoints.h>

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

struct hkpShapeRayBundleCastInput
{
    hkFourTransposedPoints m_from;
    hkFourTransposedPoints m_to;
    hkUint32 m_filterInfo;
    hkUlong m_userData;
    const hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter;
};