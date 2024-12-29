#pragma once

#include <hkpShape.h>
#include <hkBase.h>

struct hkpShapeRayCastCollectorOutput
{
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
    int m_pad[2];
};

typedef hkpShapeRayCastCollectorOutput hkpShapeRayCastCollectorOutputPpu;