#pragma once
#include <RGBA32.h>
#include <cModelDataManager.h>

class cMeshBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    RGBA32 m_Color;
    RGBA32 m_ColorScale;
    cModelData::cMaterial **m_pMaterials;
    int m_nMaterialAmount;
    int m_nMeshFlags;
    int field_3C;
    RGBA32 field_40;
    RGBA32 field_50;
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