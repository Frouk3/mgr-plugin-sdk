#pragma once

#include <WindManager.h>
#include <hkpPrevailingWind.h>
#include <lib.h>

struct Wind
{
    int field_0;
    hkpPrevailingWind* m_PrevailingWind;
    int field_8;
    int field_C;
};

class WindManagerImplement : public WindManager
{
public:
    lib::AllocatedArray<Wind *> *m_wind;

    static inline WindManagerImplement *& ms_Instance = *(WindManagerImplement**)(shared::base + 0x1735D98);
};