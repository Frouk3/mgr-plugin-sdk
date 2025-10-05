#pragma once

#include <lib.h>
#include <eObjID.h>
#include <HkDataManagerImplement.h>

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

    lib::AllocatedArray<Unit> *m_pUnits;

    AnimationMap(Hw::cHeapVariable *allocator, void *mapData)
    {
        ((void(__thiscall *)(AnimationMap*, Hw::cHeapVariable*, void*))(shared::base + 0x4DA630))(this, allocator, mapData);
    }

    Unit &getUnitByAnim(int animId)
    {
        return ((Unit &(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7D10))(this, animId);
    }

    Unit &getUnit(int index)
    {
        return ((Unit &(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7D50))(this, index);
    }

    const char *getNameByAnim(int animId)
    {
        return ((const char *(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7D70))(this, animId);
    }

    int getLoopByAnim(int animId)
    {
        return ((int(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7DB0))(this, animId);
    }

    float getInterpolationByAnim(int animId)
    {
        return ((float(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7DF0))(this, animId);
    }

    float getStartFrameByAnim(int animId)
    {
        return ((float(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7E50))(this, animId);
    }

    int getYTranslateEaseOffByAnim(int animId)
    {
        return ((int(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D7FD0))(this, animId);
    }

    int getZTranslateEaseOffByAnim(int animId)
    {
        return ((int(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D8010))(this, animId);
    }

    int getMirrorByAnim(int animId)
    {
        return ((int(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D8050))(this, animId);
    }

    int getOtherByAnim(int animId)
    {
        return ((int(__thiscall *)(AnimationMap*, int))(shared::base + 0x4D8090))(this, animId);
    }
};

class AnimationMapResource
{
public:
    int m_nReferences;
    int m_bWantsToBeRemoved;
    eObjID m_nObject;
    AnimationMap* m_pAnimationMap;
};

class AnimationMapManager
{
public:

    virtual void tick() {}
    virtual AnimationMap *addReference(eObjID object, DataArchiveHolder *data) { return nullptr; /* nullptr for no raised exception */ } // they don't check if there's already an animation map resource for the object
    virtual void release(eObjID object) {}
    virtual ~AnimationMapManager() {}
};