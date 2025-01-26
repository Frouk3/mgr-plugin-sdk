#pragma once

#include <hkpShapeRayCastInput.h>
#include <hkcdShape.h>

class hkpRayShapeCollectionFilter
{
public:

    virtual bool isCollisionEnabled(const hkpShapeRayCastInput &aInput, const void *bContainer, hkcdShapeType::ShapeTypeEnum bKey) { return false; };
};