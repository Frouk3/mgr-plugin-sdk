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
    short m_nBoneIndex;
    struct PartsProperties
    {
        unsigned short bProcessEulerRotation : 1;   // 0x1
        unsigned short bExternalRotation : 1;       // 0x2
        unsigned short bWorldFixed : 1;             // 0x4
        unsigned short bIgnoreLocalScale : 1;       // 0x8
        unsigned short b05 : 1;                     // 0x10
        unsigned short b06 : 1;                     // 0x20  
        unsigned short bAUXMatrixOrder : 1;         // 0x40  
        unsigned short b08 : 1;                     // 0x80  

        unsigned short b09 : 1;                     // 0x100  
        unsigned short b10 : 1;                     // 0x200 
        unsigned short b11 : 1;                     // 0x400 
        unsigned short b12 : 1;                     // 0x800     
        unsigned short b13 : 1;                     // 0x1000        
        unsigned short bInheritNonUniformScale : 1; // 0x2000    
        unsigned short bSkipRotationCalculation : 1;// 0x4000
        unsigned short b16 : 1;                     // 0x8000
    } m_PartsFlag;
    int field_A4;
    cParts* m_pParentBone;
    int field_AC;

    cParts()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x607410))(this);
    }

    void calculateWorldMatrix()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x615310))(this);
    }

    void calculateLocalTransformation()
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x615190))(this);
    }

    virtual ~cParts() {};

	cVec4& getPosition()
	{
		return *(cVec4*)m_PositionMatrix.m[3];
	}
};

VALIDATE_SIZE(cParts, 0xB0);