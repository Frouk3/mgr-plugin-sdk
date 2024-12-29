#pragma once

#include <hkBase.h>
#include <hkContactPoint.h>
#include <hkpCollidable.h>

struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable *m_rootCollidableA;
    hkpShapeKey m_shapeKeyA;
    const hkpCollidable *m_rootCollidableB;
    hkpShapeKey m_shapeKeyB;
};