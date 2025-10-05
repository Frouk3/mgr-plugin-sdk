#pragma once

#include <BehaviorSystem.h>
#include <Hw.h>

class BehaviorList
{
public:
    class BehaviorInfo;

    class _BEHAVIOR_INFO
    {
    public:
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        BehaviorList::BehaviorInfo *field_18;
        int m_nListCapacity;
        Hw::cHeapVariable *m_pAllocator;
        int field_24;
        Hw::CriticalSection m_ListCriticalSection;
        int field_44;
        int field_48[18][2];
        int field_D8;
        int field_DC;
        int field_E0[128][2];

        virtual ~_BEHAVIOR_INFO() {}
    };

    unsigned int m_nBehaviorCapacity;
    Hw::cHeapVariable *field_4;
    Hw::cHeapVariable *field_8;
    int field_C;
    BehaviorList::_BEHAVIOR_INFO m_BehaviorInfo;

    class BehaviorInfo
    {
    public:
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
    };
};

class SceneBehaviorSystem : public BehaviorSystem
{
public:
    int field_4;
    BehaviorList m_BehaviorList;
    int field_4F8;
    int field_4FC;
    Hw::CriticalSection field_500;
    int field_51C;
    Hw::CriticalSection field_520;
    int field_53C;
    int field_540;

    virtual ~SceneBehaviorSystem() {}

    static inline SceneBehaviorSystem& ms_Instance = *(SceneBehaviorSystem*)(shared::base + 0x14A4F90);
};