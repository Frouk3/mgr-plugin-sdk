#pragma once

#include <hkBaseObject.h>

class hkReferencedObject : public hkBaseObject
{
public:
	short m_memAndSizeFlags;
	short m_referenceCount;

	virtual hkClass* getClassType() {};
};

VALIDATE_SIZE(hkReferencedObject, 0x8);