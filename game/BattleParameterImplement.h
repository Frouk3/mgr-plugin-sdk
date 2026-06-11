#pragma once

#include <BattleParameter.h>
#include <lib.h>

class BattleParameterImplement : public BattleParameter
{
public:
    struct Unit
    {
        int m_nId;
        int m_nAtkPower;
        int m_nAtkHavokMulScalar;
        int m_nAtkHavokPow;
        int m_nHitStopTime;
        int m_Int0;
        int m_Int1;
        float m_Float0;
        float m_Float1;
        float m_Float2;
        float m_Float3;
        int m_nNo;
        float m_fEasyPowerScale;
        float m_fHardPowerScale;
        float m_fVeryhardPowerScale;
        float m_fRevengeancePowerScale;
        int m_Int3;
        int m_Int4;
        int m_Int5;
    };

    Hw::cHeapVariable *m_Allocator;
    lib::AllocatedArray<Unit> *m_Units;

    virtual int getId(int id) { return 0; } // what

    int getAttackPower(int id)
    {
        return MAKE_VCALL(1, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getAttackPowerByNo(int no)
    {
        return MAKE_VCALL(2, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getAttackHavokMulScalar(int id)
    {
        return MAKE_VCALL(3, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getAttackHavokMulScalarByNo(int no)
    {
        return MAKE_VCALL(4, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getAttackPowerHavokPow(int id)
    {
        return MAKE_VCALL(5, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getAttackPowerHavokPowByNo(int no)
    {
        return MAKE_VCALL(6, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getHitStopTime(int id)
    {
        return MAKE_VCALL(7, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getHitStopTimeByNo(int no)
    {
        return MAKE_VCALL(8, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getInt0(int id)
    {
        return MAKE_VCALL(9, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getInt0ByNo(int no)
    {
        return MAKE_VCALL(10, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getInt1(int id)
    {
        return MAKE_VCALL(11, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getInt1ByNo(int no)
    {
        return MAKE_VCALL(12, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getFloat0(int id)
    {
        return MAKE_VCALL(13, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getFloat0ByNo(int no)
    {
        return MAKE_VCALL(14, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getFloat1(int id)
    {
        return MAKE_VCALL(15, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getFloat1ByNo(int no)
    {
        return MAKE_VCALL(16, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getFloat2(int id)
    {
        return MAKE_VCALL(17, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getFloat2ByNo(int no)
    {
        return MAKE_VCALL(18, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getFloat3(int id)
    {
        return MAKE_VCALL(19, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getFloat3ByNo(int no)
    {
        return MAKE_VCALL(20, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getNo(int id)
    {
        return MAKE_VCALL(21, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getNoByNo(int no) // why
    {
        return MAKE_VCALL(22, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getEasyPowerScale(int id)
    {
        return MAKE_VCALL(23, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getEasyPowerScaleByNo(int no)
    {
        return MAKE_VCALL(24, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getHardPowerScale(int id)
    {
        return MAKE_VCALL(25, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getHardPowerScaleByNo(int no)
    {
        return MAKE_VCALL(26, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getVeryhardPowerScale(int id)
    {
        return MAKE_VCALL(27, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getVeryhardPowerScaleByNo(int no)
    {
        return MAKE_VCALL(28, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    float getRevengeancePowerScale(int id)
    {
        return MAKE_VCALL(29, float(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    float getRevengeancePowerScaleByNo(int no)
    {
        return MAKE_VCALL(30, float(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getInt3(int id)
    {
        return MAKE_VCALL(31, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getInt3ByNo(int no)
    {
        return MAKE_VCALL(32, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getInt4(int id)
    {
        return MAKE_VCALL(33, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getInt4ByNo(int no)
    {
        return MAKE_VCALL(34, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }

    int getInt5(int id)
    {
        return MAKE_VCALL(35, int(__thiscall *)(BattleParameterImplement *, int), this, id);
    }

    int getInt5ByNo(int no)
    {
        return MAKE_VCALL(36, int(__thiscall *)(BattleParameterImplement *, int), this, no);
    }
    /*
    // We still don't know what this function does
    int blank(int a2)
    {
        return ReturnCallVMTFunc<int, 38, BattleParameterImplement *, int>(this, a2);
    }
    */

    BattleParameterImplement(Hw::cHeapVariable *pAllocator, void *bin)
    {
        MAKE_CALL(shared::base + 0x975270, void(__thiscall *)(BattleParameterImplement*, Hw::cHeapVariable*, void *), this, pAllocator, bin);
    }

    ~BattleParameterImplement()
    {
        MAKE_CALL(shared::base + 0x9752A0, void(__thiscall *)(BattleParameterImplement*), this);
    }
};

VALIDATE_SIZE(BattleParameterImplement, 0xC);