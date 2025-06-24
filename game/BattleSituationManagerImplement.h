#pragma once

#include <BattleSituationManager.h>
#include <Hw.h>

class BattleSituationManagerImplement : public BattleSituationManager
{
public:
    Hw::cHeapVariable *m_Allocator;
    int *field_8;

    static inline BattleSituationManagerImplement *get()
    {
        return ((BattleSituationManagerImplement*(__cdecl*)())(shared::base + 0x972B30))();
    }

    static inline BattleSituationManagerImplement*& ms_Instance = *(BattleSituationManagerImplement**)(shared::base + 0x19C5264);
};