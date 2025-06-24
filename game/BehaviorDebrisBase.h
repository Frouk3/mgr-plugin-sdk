#pragma once

#include <Behavior.h>
#include <Slot.h>
#include <hkpPhantomOverlapListener.h>

class BehaviorDebrisBase : public Behavior
{
public:
    class DebrisPhantomListener : public hkpPhantomOverlapListener
    {
    public:

    };

    class DiscreateSlot : public Slot
    {
    public:
        BehaviorDebrisBase *m_Owner;
    };

    class ExplosionSlot : public Slot
    {
    public:
        BehaviorDebrisBase* m_Owner;
    };
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    float field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    float field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    float field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    float field_900;
    ExplosionSlot *m_ExplosionSlot;
    DiscreateSlot *m_DiscreateSlot;
    int field_90C;
    int field_910;
    EntityHandle field_914;
    int field_918;
    float field_91C;
    int field_920;
    float field_924;
    int field_928;
    int field_92C;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    float field_94C;
    int field_950;
    int field_954;
    float field_958;
    int field_95C;
    int field_960;
    int field_964;
    int field_968;
    int field_96C;

    BehaviorDebrisBase()
    {
        ((void(__thiscall *)(BehaviorDebrisBase *))(shared::base + 0x1D9E20))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735300); 
};

VALIDATE_SIZE(BehaviorDebrisBase, 0x970);