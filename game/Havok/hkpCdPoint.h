#pragma once

#include <hkBase.h>
#include <hkContactPoint.h>

class hkpCdBody;

struct hkpCdPoint
{
    hkContactPoint m_contact;
    hkVector4 m_unweldedNormal;
    const hkpCdBody& m_cdBodyA;
	const hkpCdBody& m_cdBodyB;
};