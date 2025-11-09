#pragma once

#include <Hw.h>
#include <cViewFrustum.h>
class cCameraFrustum
{
public:
    __declspec(align(16)) cViewFrustum m_Vfrustum;
    int m_bFrustum;
    int field_94;
    int field_98;
    int field_9C;

    virtual ~cCameraFrustum() {};
};

VALIDATE_SIZE(cCameraFrustum, 0xA0);