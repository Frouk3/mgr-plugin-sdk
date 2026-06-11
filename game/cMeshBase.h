#pragma once
#include <Hw.h>
#include <cModelDataManager.h>

class cMeshBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    Hw::cFcol m_Color;
    Hw::cFcol m_ColorScale;
    cMaterial **m_ppMaterials;
    int m_MaterialNum;
    int m_MeshFlags;
    int field_3C;
    Hw::cFcol field_40;
    Hw::cFcol field_50;
    int m_pMeshData;
    cParts *m_pAttachBone;
    int field_68;
    int field_6C;

    cMeshBase()
    {
        MAKE_CALL(shared::base + 0x611AA0, void(__thiscall *)(cMeshBase *), this);
    }

    inline const char *getName()
    {
        if (*(int*)m_pMeshData)
            return *(const char**)(m_pMeshData + 0x40);

        return "\0";
    }

    virtual ~cMeshBase() {};
};