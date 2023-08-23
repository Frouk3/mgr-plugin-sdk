#pragma once

#include "BattleCollisionFilter.h"
#include "Hw.h"
#include "lib.h"

class BattleCollisionFilterImplement : public BattleCollisionFilter
{
public:
    struct LayerPair
    {
        int field_0;
        int field_4;
    };
    Hw::cHeapVariable *m_pHeapVariable;
    lib::StaticArray<LayerPair, 1024> *m_pLayerPairArray;

    static inline BattleCollisionFilterImplement *&pInstance = *(BattleCollisionFilterImplement **)(shared::base + 0x19C52E0);
};