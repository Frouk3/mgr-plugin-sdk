#pragma once
#include "NinjaRunEventManager.h"

#include "Hw.h"
#include "lib.h"

namespace FreeRunActivity
{
    struct Info
    {
        int field_0;
        int field_4;
        float field_8;
        float field_C;
        float field_10;
        float field_14;
        int field_18;
        float field_1C;
        int field_20;
        int field_24;
        int field_28;
        int field_2C;
        int field_30;
        int field_34;
        int field_38;
        int field_3C;
        float field_40;
        float field_44;
        float field_48;
        float field_4C;
        float field_50;
        float field_54;
        float field_58;
        float field_5C;
        EntityHandle field_60;
        EntityHandle field_64;
        int field_68;
        int field_6C;
    };
};
// -fix me
// -later
class NinjaRunEventManagerImplement : public NinjaRunEventManager
{
public:
    class PhantomUnit
    {
    public:
        int field_4;
        int field_8;
        int field_C;
        Hw::cHeapVariable* field_10;
        int field_14;
        int field_18;
        int field_1C;
        EntityHandle field_20;
        int field_24;
        int field_28;
        int field_2C;
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
        int field_60;
        int field_64;
        int field_68;
        int field_6C;
        int field_70;
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
        int field_B0;
        int field_B4;
        int field_B8;
        int field_BC;
        int field_C0;
        int field_C4;
        int field_C8;
        int field_CC;
        int field_D0;
        int field_D4;
        int field_D8;
        int field_DC;
        int field_E0;
        int field_E4;
        int field_E8;
        int field_EC;
        EntityHandle field_F0;
        int field_F4;
        int field_F8;
        int field_FC;
        int field_10C;
        int field_110;
        int field_114;
        int field_118;
        int field_100;
        int field_104;
        int field_108;
        int field_11C;
        int field_120;
        int field_124;
        int field_128;
        int field_12C;
        int field_130;
        int field_134;
        int field_138;
        int field_13C;
        int field_140;
        int field_144;
        int field_148;
        int field_14C;
        int field_150;
        int field_154;
        int field_158;
        int field_15C;
        int field_160;
        int field_164;
        int field_168;
        int field_16C;
        lib::AllocatedArray<PhantomUnit*>* field_170;
        int field_174;
        int field_178;
        int field_17C;

        virtual void field_0() {};
        virtual ~PhantomUnit() {};
    };

    class EventUnit : PhantomUnit
    {
    public:
    };

    class RegionUnit : public PhantomUnit
    {
    public:

    };

    class PointUnit : public PhantomUnit
    {
    public:
    };

    Hw::cHeapVariable *m_pHeapVariable;
    lib::AllocatedArray<EventUnit *> *m_pAllocatedEventUnitArray;
    int field_C;
    int field_10;
    int field_14;
    int field_18;

    static inline NinjaRunEventManagerImplement*& pInstance = *(NinjaRunEventManagerImplement**)(shared::base + 0x17EA188);
};