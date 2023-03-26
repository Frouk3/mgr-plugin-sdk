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

    virtual void Function0() {};
    virtual int Function1(int a2, Entity* a3, int a4) {};
    virtual int Function2(float *a2, int a3, float* a4) {};
    virtual ~SituationManagerImplement() override {};
};

extern SituationManagerImplement*& g_pSituationManagerImplement;