#pragma once
#include "SituationManager.h"
#include "Entity.h"
#include "Hw.h"

class SituationManagerImplement : public SituationManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;

    virtual ~SituationManagerImplement() override {};
};

SituationManagerImplement *GetSituationManagerImplement();
extern SituationManagerImplement*& g_pSituationManagerImplement;