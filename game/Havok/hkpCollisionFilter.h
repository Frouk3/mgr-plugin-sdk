#pragma once

#include <hkBaseObject.h>
#include <hkpCollidableCollidableFilter.h>
#include <hkpShapeCollectionFilter.h>
#include <hkpRayShapeCollectionFilter.h>
#include <hkpRayCollidableFilter.h>

class hkpCollisionFilter : public hkReferencedObject, public hkBaseObject, public hkpCollidableCollidableFilter, public hkpShapeCollectionFilter, public hkpRayShapeCollectionFilter, public hkpRayCollidableFilter
{

};