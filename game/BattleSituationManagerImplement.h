#pragma once
#include "BattleSituationManager.h"
#include "Hw.h"

class BattleSituationManagerImplement : public BattleSituationManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    int *field_8;

    virtual ~BattleSituationManagerImplement() override {};
};

extern BattleSituationManagerImplement*& g_pBattleSituationManagerImplement;
BattleSituationManagerImplement* GetBattleSituationManagerImplement();