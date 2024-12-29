#pragma once

#include <hkBase.h>
#include <hkcdShape.h>

class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
struct hkpShapeRayBundleCastInput;
struct hkpShapeRayBundleCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
class hkpConvexShape;

typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;

class hkpShapeBase : public hkcdShape
{
public:
    
};