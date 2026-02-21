#pragma once

#include <lib.h>
#include <eObjID.h>
#include <Hw.h>

struct AnimationMap
{
    struct Unit
    {
        int m_Id;
        int field_4;
        char m_pName[4];
        int field_C;
        int m_Loop;
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

    lib::AllocatedArray<Unit> *m_pUnits;

    AnimationMap(Hw::cHeapVariable *allocator, void *mapData) { CallMethod<0x4DA630, AnimationMap *, Hw::cHeapVariable *, void *>(this, allocator, mapData); }
    Unit *getUnitByAnim(int animId) { return ReturnCallMethod<Unit*, 0x4D7D10, AnimationMap *, int>(this, animId); }
    Unit *getUnit(int index) { return ReturnCallMethod<Unit*, 0x4D7D50, AnimationMap *, int>(this, index); }
    const char *getNameByAnim(int animId) { return ReturnCallMethod<const char*, 0x4D7D70, AnimationMap *, int>(this, animId); }
    int getLoopByAnim(int animId) { return ReturnCallMethod<int, 0x4D7DB0, AnimationMap *, int>(this, animId); }
    float getInterpolationByAnim(int animId) { return ReturnCallMethod<float, 0x4D7DF0, AnimationMap *, int>(this, animId); }
    float getStartFrameByAnim(int animId) { return ReturnCallMethod<float, 0x4D7E50, AnimationMap *, int>(this, animId); }
    int getYTranslateEaseOffByAnim(int animId) { return ReturnCallMethod<int, 0x4D7FD0, AnimationMap *, int>(this, animId); }
    int getZTranslateEaseOffByAnim(int animId) { return ReturnCallMethod<int, 0x4D8010, AnimationMap *, int>(this, animId); }
    int getMirrorByAnim(int animId) { return ReturnCallMethod<int, 0x4D8050, AnimationMap *, int>(this, animId); }
    int getOtherByAnim(int animId) { return ReturnCallMethod<int, 0x4D8090, AnimationMap *, int>(this, animId); }
};

class AnimationMapResource
{
public:
    int m_RefCount;
    int m_bWantsToBeRemoved;
    eObjID m_Object;
    AnimationMap* m_pAnimationMap;
};

class AnimationMapManager
{
public:

    virtual void tick() {}
    virtual AnimationMap *addReference(eObjID object, Hw::cFmerge *data) { return nullptr; /* nullptr for no raised exception */ } // they don't check if there's already an animation map resource for the object
    virtual void release(eObjID object) {}
    virtual ~AnimationMapManager() {}
};