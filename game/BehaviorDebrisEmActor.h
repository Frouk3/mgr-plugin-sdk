#pragma once

#include <Behavior.h>
#include <Slot.h>
#include <hkpPhantomOverlapListener.h>

class BehaviorDebrisEmActor : public Behavior
{
public:
    class DebrisPhantomListener : public hkpPhantomOverlapListener
    {
    public:
    };

    class ExplosionSlot : public Slot
    {
    public:
        BehaviorDebrisEmActor *m_Owner;
    };
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
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
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;

    BehaviorDebrisEmActor()
    {
        ((void (__thiscall *)(BehaviorDebrisEmActor *))(shared::base + 0x6A6B60))(this);
    }
};