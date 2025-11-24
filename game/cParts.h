#pragma once

#include <Hw.h>
#include <shared.h>
#include <d3dx9math.h>
#include <HwMath.h>

class cParts
{
private:
    int _pad00[3]; // 0x4 -> 0x10
public:
    Hw::cMtx m_LocalMatrix;
    Hw::cVec4 m_TransPos;
    Hw::cQuat m_QuatRot;
    Hw::cVec4 m_Scale;
    Hw::cVec4 m_WorldScale;
    Hw::cVec4 m_Rot;
    short m_PartsNo;
    struct PartsProperties
    {
        union 
        {
            struct
            {            
                unsigned short bUpdateMatRot : 1;   // 0x1
                unsigned short bLocalMatOff : 1;       // 0x2
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
            };
            unsigned short m_Flag;
        };
    } m_PartsFlag;
    Hw::cMtx* m_pMulMtx;
    cParts* m_pPartsParent;
    int field_AC; // maybe unused and/or padding

    cParts() { CallMethod<0x607410, cParts *>(this); }
    void init(const cParts& other, BOOL bWorldFixed) { CallMethod<0x6074D0, cParts *, const cParts&, BOOL>(this, other, bWorldFixed); } // it was a copy constructor, but it didn't mention virtual table setup, so I made it a normal method
    void init(const Hw::cVec4& transPos, short boneIndex) { CallMethod<0x6075A0, cParts *, const Hw::cVec4&, short>(this, transPos, boneIndex); }
    void convertRotationToQuaternion() { CallMethod<0x3F790, cParts *>(this); }
    void updateLocalMatrix() { CallMethod<0x615310, cParts *>(this); }
    void updateLocalTransform() { CallMethod<0x615190, cParts *>(this); }

    virtual ~cParts() {} // Non virtual destructor at 0x6074C0

	const Hw::cVec4& getPos() { return m_LocalMatrix.r[3]; }
};

VALIDATE_SIZE(cParts, 0xB0);