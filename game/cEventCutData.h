#pragma once

#include <Hw.h>

class cEventCutData
{
public:
    int field_4;
    int field_8;
    int field_C;
    cVec4 m_vecViewTargetPos;
    cVec4 m_vecViewTrans;
    int m_nInterpolationType;
    int m_fFrame;
    float m_fInterpolationValue;
    float m_fFovY;
    unsigned int m_nFlag;
    int field_44;
    float field_48;
    float field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;

    virtual ~cEventCutData() {};
};

class cEventCutWork
{
public:
    int field_4;
    int field_8;
    int field_C;
    cVec4 m_vecPlayerRot;
    cVec4 m_vecSoftEvEndCamRot;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    Hw::cHeapVariable *m_Allocator;
    int m_nSynthesisFrame;
    int m_nCutNo;
    unsigned int m_nFlag;
    int field_54;
    int field_58;
    int field_5C;

    virtual void dummyVM() {};
};