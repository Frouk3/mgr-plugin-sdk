#pragma once
#include "Hw.h"
#include "shared.h"
#include <d3dx9math.h>

class cParts
{
public:
    int field_4;
    int field_8;
    int field_C;
    D3DXMATRIX m_PartsMatrix;
    Hw::cVec4 m_vecTransPos;
    float field_60;
    float field_64;
    float field_68;
    float field_6C;
    Hw::cVec4 m_vecSize;
    float field_80;
    float field_84;
    float field_88;
    int field_8C;
    Hw::cVec4 m_vecRotation;
    short m_nPartIndex;
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
    } m_nPartsFlag;
    int field_A4;
    int field_A8;
    int field_AC;

    void updateMatrix()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x615310))(this);
    }

    virtual ~cParts() {};
};

VALIDATE_SIZE(cParts, 0xB0);