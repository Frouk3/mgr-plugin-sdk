#pragma once

#include <Hw.h>
#include <shared.h>
#include <d3dx9math.h>
#include <HwMath.h>

class cParts
{
public:
    __declspec(align(16)) Hw::cMtx m_LocalMatrix;
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
    int field_AC;

    cParts() { ((void(__thiscall*)(cParts*))(shared::base + 0x607410))(this); }
    cParts(const cParts& other, BOOL bWorldFixed) { ((void(__thiscall*)(cParts*, const cParts&, BOOL))(shared::base + 0x6074D0))(this, other, bWorldFixed); }
    void init(const Hw::cVec4& transPos, short boneIndex) { ((void(__thiscall*)(cParts*, const Hw::cVec4&, short))(shared::base + 0x6075A0))(this, transPos, boneIndex); }
    void convertRotationToQuaternion() { ((void(__thiscall*)(cParts*))(shared::base + 0x3F790))(this); }
    void updateLocalMatrix() { ((void(__thiscall*)(cParts*))(shared::base + 0x615310))(this); }
    void updateLocalTransform() { ((void(__thiscall*)(cParts*))(shared::base + 0x615190))(this); }

    virtual ~cParts() {};

    /*
    ~cParts() // non-virtual destructor 
    {
        ((void(__thiscall*)(cParts*))(shared::base + 0x6074C0))(this);
    }
    */

	Hw::cVec4& getPosition() { return m_LocalMatrix.r[3]; }
};

VALIDATE_SIZE(cParts, 0xB0);