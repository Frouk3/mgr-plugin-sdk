#pragma once
#include "ARGB32.h"

class cMeshBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    ARGB32 m_rgbForceColor;
    ARGB32 m_rgbColor;
    int field_30;
    int field_34;
    int m_nMeshFlags;
    int field_3C;
    ARGB32 field_40;
    ARGB32 field_50;
    int m_pMaterialInfo;
    cParts* m_pAttachBone;
    int field_68;
    int field_6C;

    inline const char *getName()
    {
        if (*(int*)m_pMaterialInfo)
            return *(const char**)(m_pMaterialInfo + 0x40);
    }

    virtual ~cMeshBase() {};
};