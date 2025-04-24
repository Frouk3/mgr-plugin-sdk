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
    cModelData::cMaterial **m_Materials;
    int m_MaterialAmount;
    int m_MeshFlags;
    int field_3C;
    RGBA32 field_40;
    RGBA32 field_50;
    int m_MeshData;
    cParts *m_AttachBone;
    int field_68;
    int field_6C;

    inline const char *getName()
    {
        if (*(int*)m_MeshData)
            return *(const char**)(m_MeshData + 0x40);

        return nullptr;
    }

    virtual ~cMeshBase() {};
};