#pragma once

#include <lib.h>
#include <eObjID.h>

struct AnimationMap
{
    struct Unit
    {
        int m_nId;
        int field_4;
        char m_name4[4];
        int field_C;
        int m_nLoop;
        float m_fInterpolate;
        float m_fStartFrame;
        float m_fCancelStartFrame;
        float m_fCancelValidFrame;
        int m_nCancelToFreeFall;
        int m_nCancelToLanding;
        int m_nYTranslateEaseOff;
        int m_nZTranslateEaseOff;
        int m_nMirror;
        int m_nOther;
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