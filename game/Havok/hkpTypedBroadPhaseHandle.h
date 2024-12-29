#pragma once

#include <hkBase.h>

#include <hkpBroadPhaseHandle.h>

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:

protected:
    enum { OFFSET_INVALID = 127 };
    friend class hkpBroadPhaseBorder;

    hkInt8 m_type;
    hkInt8 m_ownerOffset;
public:
    hkInt8 m_objectQualityType;
	hkUint32 m_collisionFilterInfo;
};