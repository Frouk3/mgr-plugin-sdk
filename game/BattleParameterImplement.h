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

    virtual int getId(int id) {} // what

    int getAttackPower(int id)
    {
        return ReturnCallVMTFunc<int, 1, BattleParameterImplement *, int>(this, id);
    }

    int getAttackPowerByNo(int no)
    {
        return ReturnCallVMTFunc<int, 2, BattleParameterImplement *, int>(this, no);
    }

    int getAttackHavokMulScalar(int id)
    {
        return ReturnCallVMTFunc<int, 3, BattleParameterImplement *, int>(this, id);
    }

    int getAttackHavokMulScalarByNo(int no)
    {
        return ReturnCallVMTFunc<int, 4, BattleParameterImplement *, int>(this, no);
    }

    int getAttackPowerHavokPow(int id)
    {
        return ReturnCallVMTFunc<int, 5, BattleParameterImplement *, int>(this, id);
    }

    int getAttackPowerHavokPowByNo(int no)
    {
        return ReturnCallVMTFunc<int, 6, BattleParameterImplement *, int>(this, no);
    }

    int getHitStopTime(int id)
    {
        return ReturnCallVMTFunc<int, 7, BattleParameterImplement *, int>(this, id);
    }

    int getHitStopTimeByNo(int no)
    {
        return ReturnCallVMTFunc<int, 8, BattleParameterImplement *, int>(this, no);
    }

    int getInt0(int id)
    {
        return ReturnCallVMTFunc<int, 9, BattleParameterImplement *, int>(this, id);
    }

    int getInt0ByNo(int no)
    {
        return ReturnCallVMTFunc<int, 10, BattleParameterImplement *, int>(this, no);
    }

    int getInt1(int id)
    {
        return ReturnCallVMTFunc<int, 11, BattleParameterImplement *, int>(this, id);
    }

    int getInt1ByNo(int no)
    {
        return ReturnCallVMTFunc<int, 12, BattleParameterImplement *, int>(this, no);
    }

    float getFloat0(int id)
    {
        return ReturnCallVMTFunc<float, 13, BattleParameterImplement *, int>(this, id);
    }

    float getFloat0ByNo(int no)
    {
        return ReturnCallVMTFunc<float, 14, BattleParameterImplement *, int>(this, no);
    }

    float getFloat1(int id)
    {
        return ReturnCallVMTFunc<float, 15, BattleParameterImplement *, int>(this, id);
    }

    float getFloat1ByNo(int no)
    {
        return ReturnCallVMTFunc<float, 16, BattleParameterImplement *, int>(this, no);
    }

    float getFloat2(int id)
    {
        return ReturnCallVMTFunc<float, 17, BattleParameterImplement *, int>(this, id);
    }

    float getFloat2ByNo(int no)
    {
        return ReturnCallVMTFunc<float, 18, BattleParameterImplement *, int>(this, no);
    }

    float getFloat3(int id)
    {
        return ReturnCallVMTFunc<float, 19, BattleParameterImplement *, int>(this, id);
    }

    float getFloat3ByNo(int no)
    {
        return ReturnCallVMTFunc<float, 20, BattleParameterImplement *, int>(this, no);
    }

    int getNo(int id)
    {
        return ReturnCallVMTFunc<int, 21, BattleParameterImplement *, int>(this, id);
    }

    int getNoByNo(int no) // why
    {
        return ReturnCallVMTFunc<int, 22, BattleParameterImplement *, int>(this, no);
    }

    float getEasyPowerScale(int id)
    {
        return ReturnCallVMTFunc<int, 23, BattleParameterImplement *, int>(this, id);
    }

    float getEasyPowerScaleByNo(int no)
    {
        return ReturnCallVMTFunc<float, 24, BattleParameterImplement *, int>(this, no);
    }

    float getHardPowerScale(int id)
    {
        return ReturnCallVMTFunc<int, 25, BattleParameterImplement *, int>(this, id);
    }

    float getHardPowerScaleByNo(int no)
    {
        return ReturnCallVMTFunc<float, 26, BattleParameterImplement *, int>(this, no);
    }

    float getVeryhardPowerScale(int id)
    {
        return ReturnCallVMTFunc<float, 27, BattleParameterImplement *, int>(this, id);
    }

    float getVeryhardPowerScaleByNo(int no)
    {
        return ReturnCallVMTFunc<float, 28, BattleParameterImplement *, int>(this, no);
    }

    float getRevengeancePowerScale(int id)
    {
        return ReturnCallVMTFunc<float, 29, BattleParameterImplement *, int>(this, id);
    }

    float getRevengeancePowerScaleByNo(int no)
    {
        return ReturnCallVMTFunc<float, 30, BattleParameterImplement *, int>(this, no);
    }

    int getInt3(int id)
    {
        return ReturnCallVMTFunc<int, 31, BattleParameterImplement *, int>(this, id);
    }

    int getInt3ByNo(int no)
    {
        return ReturnCallVMTFunc<int, 32, BattleParameterImplement *, int>(this, no);
    }

    int getInt4(int id)
    {
        return ReturnCallVMTFunc<int, 33, BattleParameterImplement *, int>(this, id);
    }

    int getInt4ByNo(int no)
    {
        return ReturnCallVMTFunc<int, 34, BattleParameterImplement *, int>(this, no);
    }

    int getInt5(int id)
    {
        return ReturnCallVMTFunc<int, 35, BattleParameterImplement *, int>(this, id);
    }

    int getInt5ByNo(int no)
    {
        return ReturnCallVMTFunc<int, 36, BattleParameterImplement *, int>(this, no);
    }
    /*
    // We still don't know what this function does
    int blank(int a2)
    {
        return ReturnCallVMTFunc<int, 38, BattleParameterImplement *, int>(this, a2);
    }
    */
    ~BattleParameterImplement()
    {
        CallVMTFunc<39, BattleParameterImplement *, char>(this, 0);
    }
};

VALIDATE_SIZE(BattleParameterImplement, 0xC);