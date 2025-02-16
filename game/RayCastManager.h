#pragma once

#include <Hw.h>
#include <hkpCollidable.h>
#include <common.h>
#include <hkpAllCdPointCollector.h>
#include <hkpAllRayHitCollector.h>

class RayCastManager
{
public:
    int field_4;
    int field_8;
    int field_C;
    Hw::cHeapVariable m_RayCastFactory;
    Hw::cFixedVector<int> field_68;
    Hw::cFixedVector<int> field_7C[5];
    int field_E0;
    int field_E4;
    Hw::CriticalSection field_E8;
    int field_104;
    Hw::CriticalSection field_108;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138[5];
    void *field_14C[5]; // huh?
};

class RayCastWork
{
public:
    int m_nRayWorkType;
    short field_8;
    short field_A;
    short field_C;
    short field_E;
    int field_10;
    char field_14;
    char field_15;
    char field_16;
    char field_17;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    char field_1C;
    char field_1D;
    char field_1E;
    char field_1F;

    virtual ContextInstance& getContext() {static ContextInstance context; return context; };
    virtual ~RayCastWork() {};
};

class RayCastSingleHitWork : public RayCastWork
{
public:
    cVec4 field_20;
    cVec4 field_30;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    cVec4 field_60;
    float field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    hkpCollidable *field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    cVec4 field_C0;
    cVec4 field_D0;
};

class RayCastMultiHitWork : public RayCastWork
{
public:
    cVec4 field_20;
    cVec4 field_30;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    hkpAllRayHitCollector m_RayHitCollector;
    cVec4 field_380;
    cVec4 field_390;
};

class RayCastPenetrationWork : public RayCastWork
{
public:
    int field_20;
    int field_24;
    int field_28;
    char field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
};

class RayCastLinearWork : public RayCastWork
{
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    cVec4 field_30;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    cVec4 field_50;
    hkpAllCdPointCollector m_CdCollector;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
};

class RayCastClosestPointsWork : public RayCastWork
{
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    hkpAllCdPointCollector m_CdPointCollector;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
};

VALIDATE_SIZE(RayCastWork, 0x20);
VALIDATE_SIZE(RayCastMultiHitWork, 0x3A0);