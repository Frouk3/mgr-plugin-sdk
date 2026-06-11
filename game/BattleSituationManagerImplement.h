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
        return MAKE_CALL(shared::base + 0x972B30, BattleSituationManagerImplement *(__cdecl*)());
    }
};

inline BattleSituationManagerImplement*& g_BattleSituationManager = *(BattleSituationManagerImplement**)(shared::base + 0x19C5264);