#pragma once

#include <Hw.h>

class cTouchArea
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    int field_34;
    int field_38;

    virtual ~cTouchArea() {};
};

class cTouchManager
{
public:
    Hw::cFixedList<cTouchArea> m_TouchList;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;

    virtual ~cTouchManager() {};
};

namespace UICollision
{
    struct sHitData
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
    };

    class cUIHitManager
    {
    public:

        virtual ~cUIHitManager() {};
    };

    class cUIHitData
    {
    public:
        int field_4;
        Hw::cHeapVariable *m_Allocator;
        int field_C;
        Hw::CriticalSection field_10;
        int field_2C;
        Hw::cFixedVector<sHitData> m_HitData;
        int field_44;

        virtual ~cUIHitData() {};
    };

    struct sDictionary
    {
        int field_0;
        int field_4;
        cUIHitData *m_UIHitData;
    };

    class cUIHitDataManager
    {
    public:
        int field_4;
        Hw::cHeapVariable *m_Allocator;
        int field_C;
        Hw::CriticalSection m_CriticalSection;
        int field_2C;
        Hw::cFixedVector<sDictionary> m_Dictionary;
        int field_44;
        int field_48;
        int field_4C;

        virtual ~cUIHitDataManager() {};
    };

    class cUIHit
    {
        int field_4;
        Hw::cHeapVariable *m_Allocator;
        int field_C;
        Hw::CriticalSection m_CriticalSection;
        int field_2C;
        UICollision::cUIHitDataManager *m_UIDataManager;
        Hw::cFixedVector<void*> field_34; // unknown struct
        Hw::cFixedVector<void*> field_48; // unknown struct
        Hw::cFixedVector<void*> field_5C; // unknown struct
        int field_70;
        cTouchManager m_TouchManager;
        int field_D4;

        virtual ~cUIHit() {};
    };

    inline cUIHitManager *&ms_UIHitManager = *(cUIHitManager**)(shared::base + 0x19C0730);
    inline Hw::cHeapVariable *&ms_Allocator = *(Hw::cHeapVariable**)(shared::base + 0x19C0734);
    inline cUIHitDataManager *& ms_UIHitDataManager = *(cUIHitDataManager**)(shared::base + 0x19C0738);
    inline cUIHit *& ms_UIHit = *(cUIHit**)(shared::base + 0x19C073C);
};