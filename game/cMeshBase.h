#pragma once
#include <ARGB32.h>
#include <cModelDataManager.h>

class cMeshBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    ARGB32 m_rgbColor;
    ARGB32 field_20;
    cModelData::cMaterial **m_pMaterial;
    int field_34;
    int m_nMeshFlags;
    int field_3C;
    ARGB32 field_40;
    ARGB32 field_50;
    int m_pMeshData;
    cParts *m_pAttachBone;
    int field_68;
    int field_6C;

    inline const char *getName()
    {
        if (*(int*)m_pMeshData)
            return *(const char**)(m_pMeshData + 0x40);

        return nullptr;
    }

    virtual ~cMeshBase() {};
};