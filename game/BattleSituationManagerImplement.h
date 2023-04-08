#pragma once
#include "BattleSituationManager.h"
#include "Hw.h"

class BattleSituationManagerImplement : public BattleSituationManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    int *field_8;

    virtual int Function0(int a2, int a3, int a4, int a5, int a6, int a7) = 0;
    virtual void Function1() = 0;
    virtual void Function2() = 0;
    virtual ~BattleSituationManagerImplement() override {};
};

extern BattleSituationManagerImplement*& g_pBattleSituationManagerImplement;
BattleSituationManagerImplement* GetBattleSituationManagerImplement();