#pragma once

#include <hkpShapeRayCastCollectorOutput.h>

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
public:
    enum { MAX_HIERARCHY_DEPTH = 8 };

    hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
    int m_shapeKeyIndex;
};

struct hkpShapeRayBundleCastOutput
{
	hkpShapeRayCastOutput m_outputs[4];
};