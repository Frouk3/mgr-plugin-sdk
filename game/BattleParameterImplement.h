#pragma once

#include <BattleParameter.h>
#include <lib.h>

class BattleParameterImplement : public BattleParameter
{
public:
    struct Unit
    {
        int m_id;
        int m_AtkPower;
        int m_AtkHavokMulScalar;
        int m_AtkHavokPow;
        int m_HitStopTime;
        int m_Int0;
        int m_Int1;
        float m_Float0;
        float m_Float1;
        float m_Float2;
        float m_Float3;
        int m_No;
        float m_EasyPowerScale;
        float m_HardPowerScale;
        float m_VeryhardPowerScale;
        float m_RevengeancePowerScale;
        int m_Int3;
        int m_Int4;
        int m_Int5;
    };

    Hw::cHeapVariable *m_Allocator;
    lib::AllocatedArray<Unit> *m_Units;
};

VALIDATE_SIZE(BattleParameterImplement, 0xC);