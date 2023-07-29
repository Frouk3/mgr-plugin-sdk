#pragma once
#include "BattleSituationManager.h"
#include "Hw.h"

class BattleSituationManagerImplement : public BattleSituationManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    int *field_8;

};

static BattleSituationManagerImplement*& g_pBattleSituationManagerImplement = *(BattleSituationManagerImplement**)(shared::base + 0x19C5264);
BattleSituationManagerImplement* GetBattleSituationManagerImplement()
{
    return ((BattleSituationManagerImplement*(__cdecl*)())(shared::base + 0x972B30))();
}