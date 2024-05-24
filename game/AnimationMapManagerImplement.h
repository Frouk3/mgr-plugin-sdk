#pragma once

#include "AnimationMapManager.h"
#include "Hw.h"
#include "lib.h"

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

class AnimationMapManagerImplement : public AnimationMapManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    lib::AllocatedArray<AnimationMapResource *> *m_pAnimationMapResourceArray;
    int field_2C;

    void tick()
    {
        CallVMTFunc<0, AnimationMapManagerImplement*>(this);
    
    }

    // Returns array of animation map array
    lib::AllocatedArray<AnimationMap::Unit> **addReference(eObjID object, void *fileOpener)
    {
        return ReturnCallVMTFunc<lib::AllocatedArray<AnimationMap::Unit>**, 1, AnimationMapManagerImplement*, eObjID, void*>(this, object, fileOpener);
    }

    // Removes reference of object
    void removeReference(eObjID object)
    {
        CallVMTFunc<2, AnimationMapManagerImplement*, eObjID>(this, object);
    }

    ~AnimationMapManagerImplement()
    {
        CallVMTFunc<3, AnimationMapManagerImplement*, char>(this, 0);
    }

    static inline AnimationMapManagerImplement*& pInstance = *(AnimationMapManagerImplement**)(shared::base + 0x1735BF4);
};

VALIDATE_SIZE(AnimationMap::Unit, 0x3C);