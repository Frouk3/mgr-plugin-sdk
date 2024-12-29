#pragma once

#include <hkBase.h>
#include <hkpCdBody.h>
#include <hkpTypedBroadPhaseHandle.h>

class hkAabb;
struct hkAabbUint32;
class hkpShape;
class hkTransform;

class hkpCollidable : public hkpCdBody
{
public:

    struct BoundingVolumeData
    {
    public:
		hkUint32 m_min[3];
	    hkUint8	m_expansionMin[3];
		hkUint8	m_expansionShift;
		hkUint32 m_max[3];
		hkUint8	m_expansionMax[3];
		hkUint8	m_padding;
		hkUint16 m_numChildShapeAabbs;
		hkUint16 m_capacityChildShapeAabbs;
		hkAabbUint32* m_childShapeAabbs;
		hkpShapeKey* m_childShapeKeys;
    };

    enum ForceCollideOntoPpuReasons
	{
		FORCE_PPU_USER_REQUEST = 1,	
		FORCE_PPU_SHAPE_REQUEST = 2,
		FORCE_PPU_MODIFIER_REQUEST = 4,
		FORCE_PPU_SHAPE_UNCHECKED = 8
	};
public:
    hkInt8 m_ownerOffset; 
    hkUint8 m_forceCollideOntoPpu;
    hkUint16 m_shapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle;
    BoundingVolumeData m_boundingVolumeData;
    hkReal m_allowedPenetrationDepth;
};