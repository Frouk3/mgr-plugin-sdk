#pragma once

#include <cParts.h>
#include <cMesh.h>
#include <Hw.h>
#include <cModelDataManager.h>

class cModelBase : public cParts
{
public:
    struct RenderMatrix
    {
        cVec4 m_vecPos;
        cVec4 m_vecRotation;
        cVec4 m_vecBBMin;
        cVec4 m_vecBBMax;
        cVec4 field_40;
    };

    D3DXMATRIX field_B0;
    D3DXMATRIX field_F0;
    RenderMatrix m_RenderMatrix;
    float m_fDistRate0;
    float m_fDistRate1;
    float m_fDistRate2;
    float m_fLostDistRate;
    float field_190;
    float field_194;
    float field_198;
    float field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    unsigned short field_238;
    unsigned short field_23A;
    unsigned short field_23C;
    unsigned short field_23E;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int m_bStealthCamoToggle;
    float field_314;
    int field_318;
    int field_31C;
    cMesh *m_pMesh;
    short m_nMeshAmount;
    cModelData::cMaterial *m_pMaterials;
    short m_nMaterialAmount;
    cModelData::ModelData *m_pModelData;
    cParts *m_pRootBone;
    int field_338;
    int field_33C;
    int m_nAnisotropicType;
    void *m_pWTB;
    void *m_pTextureRawData;
    Hw::cTexture *m_pTexture;
    cParts *m_pBones;
    cParts **m_ppBones;
    short m_nTotalOfBones;
    void *m_pBoneOffsetData;
    cModelBase *m_pParent;
    int m_nModelFlags;
    int m_nRootBone;
    void *m_pMeshData;

    cModelBase()
    {
        ((void(__thiscall*)(cModelBase*))(shared::base + 0x619210))(this);
    }

    inline void toggleAnyMesh(const char *meshName, bool bToggle)
    {
        if (m_nMeshAmount)
        {
            for (auto mesh = m_pMesh; mesh != &m_pMesh[m_nMeshAmount]; mesh++)
            {
                if (mesh->getName() && strstr(mesh->getName(), meshName))
                    mesh->m_nMeshFlags = bToggle ? mesh->m_nMeshFlags | 1u : mesh->m_nMeshFlags & ~1u;
            }
        }
    }

    inline void toggleMesh(const char *meshName, bool bToggle)
    {
        if (m_nMeshAmount)
        {
            for (auto mesh = m_pMesh; mesh != &m_pMesh[m_nMeshAmount]; mesh++)
            {
                if (mesh->getName() && !strcmp(mesh->getName(), meshName))
                    mesh->m_nMeshFlags = bToggle ? mesh->m_nMeshFlags | 1u : mesh->m_nMeshFlags & ~1u;
            }
        }
    }

    // returns bone without raw index
    cParts *getBone(unsigned int bone)
    {
        return ((cParts *(__thiscall *)(cModelBase *, unsigned int))(shared::base + 0x612210))(this, bone);
    }

    float calculateHeadingToTarget(const cVec4& target)
    {
        return ((float(__thiscall*)(cModelBase*, const cVec4&))(shared::base + 0x68EC30))(this, target);
    }

    void updateBones()
    {
        ((void(__thiscall*)(cModelBase*))(shared::base + 0x617A40))(this);
    }
};

VALIDATE_SIZE(cModelBase, 0x370);