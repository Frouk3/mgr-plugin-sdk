#pragma once

#include <BehaviorBm.h>
#include <Slot.h>

class Bm018f : public BehaviorBm
{
public:
    class cCallEfBm018fSlot : public Slot
    {
        Bm018f *m_Owner;
    };
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;
    int field_B80;
    int field_B84;
    int field_B88;
    int field_B8C;
};