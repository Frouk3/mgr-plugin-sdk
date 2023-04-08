#pragma once
#include "BattleParameterManager.h"
#include "Hw.h"

class BattleParameterManagerImplement : public BattleParameterManager
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

    virtual void Function0() = 0;
    virtual void* Function1(int arg0, int a2) = 0;
    virtual void Function2(int a2) = 0;
    virtual ~BattleParameterManagerImplement() override {};
};

extern BattleParameterManagerImplement*& g_pBattleParameterManagerImplement;