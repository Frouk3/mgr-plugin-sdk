#pragma once

#include <lib.h>
#include <eObjID.h>

struct AnimationMap
{
    struct Unit
    {
        int m_Id;
        int field_4;
        char m_name4[4];
        int field_C;
        int m_nLoop;
        float m_Interpolate;
        float m_StartFrame;
        float m_CancelStartFrame;
        float m_CancelValidFrame;
        int m_CancelToFreeFall;
        int m_CancelToLanding;
        int m_YTranslateEaseOff;
        int m_ZTranslateEaseOff;
        int m_Mirror;
        int m_Other;
    };
};

struct AnimationMapResource
{
    int m_nReferences;
    int m_bWantsToBeRemoved;
    eObjID m_nObject;
    lib::AllocatedArray<AnimationMap::Unit>** m_ppAnimationUnit;
};

class AnimationMapManager
{
public:

    virtual void tick() {};
    virtual lib::AllocatedArray<AnimationMap::Unit> **addReference(eObjID object, void *a3) {};
    virtual void removeReference(eObjID object) {};
    virtual ~AnimationMapManager() {};
};