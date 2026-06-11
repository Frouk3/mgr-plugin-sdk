#pragma once

#include <cEspControler.h>
#include <BattleRegionManager.h>
#include <lib.h>

class BattleRegionManagerImplement : public BattleRegionManager
{
public:
    struct Unit
    {
        int m_ID;
        float m_fTimeWeNeedThisObject;
    };
    lib::AllocatedArray<Unit>* m_Units;
    int field_8;
    int field_C;
    cEspControler field_10;

    static inline BattleRegionManagerImplement* get()
    {
        return MAKE_CALL(shared::base + 0x1110, BattleRegionManagerImplement *(__cdecl*)());
    }
};

inline BattleRegionManagerImplement*& g_BattleRegionManager = *(BattleRegionManagerImplement**)(shared::base + 0x1734B00);

VALIDATE_SIZE(BattleRegionManagerImplement, 0xC0);