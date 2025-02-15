#pragma once

#include <Hw.h>
#include <shared.h>
#include <d3dx9math.h>
#include <cMath.h>

class cParts
{
public:
    int field_4;
    int field_8;
    int field_C;
    D3DXMATRIX m_PositionMatrix;
    cVec4 m_vecTransPos;
    cQuaternion m_quatRotation;
    cVec4 m_vecSize;
    cVec4 field_80;
    cVec4 m_vecRotation;
    short m_BoneIndex;
    struct PartsProperties
    {
        unsigned short b01 : 1;
        unsigned short bFreezeModelRotation : 1;
        unsigned short bFreezePosition : 1;
        unsigned short bFreezeSize : 1;
        unsigned short b05 : 1;
        unsigned short b06 : 1;
        unsigned short b07 : 1;
        unsigned short b08 : 1;

        unsigned short b09 : 1;
        unsigned short b10 : 1;
        unsigned short b11 : 1;
        unsigned short b12 : 1;
        unsigned short b13 : 1;
        unsigned short b14 : 1;
        unsigned short bFreezeRotation : 1; // same as bFreezeModelRotation
        unsigned short b16 : 1;
    } m_PartsFlag;
    int field_A4;
    cParts* m_ParentBone;
    int field_AC;

    cParts()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x607410))(this);
    }

    void updateMatrix()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x615310))(this);
    }

    void calculateLocalTransformation()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x615190))(this);
    }

    virtual ~cParts() {};
};

VALIDATE_SIZE(cParts, 0xB0);