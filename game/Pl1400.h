#pragma once

#include <PlBaseDLC.h>

class Pl1400 : public PlBaseDLC
{
public:
    enum PL1400_R0 
    {
        PL1400_R0_WAIT = 0x100000u,
        PL1400_R0_SLOW_WALK = 0x100001u,
        PL1400_R0_WALK = 0x100002u,
        PL1400_R0_JUMP = 0x100003u,
        PL1400_R0_DOUBLE_JUMP = 0x100004u,
        PL1400_R0_FALL = 0x100005u,
        PL1400_R0_LAND = 0x100006u,
        PL1400_R0_ZANGEKI = 0x100007u,
        PL1400_R0_DASH = 0x100008u,
        PL1400_R0_RUN_JUMP = 0x100009u,
        PL1400_R0_AIR_DASH = 0x10000Cu,
        PL1400_R0_SHEATHE = 0x10000Eu,
        PL1400_R0_LIGHT_ATTACK = 0x10000Fu,
        PL1400_R0_CHARGE_COMBO = 0x100010u,
        PL1400_R0_CHARGE_STAND = 0x100011u,
        PL1400_R0_RUSH_ATTACK = 0x100012u,
        PL1400_R0_BACK_FORWARD_HEAVY = 0x100013u,
        PL1400_R0_RUN_ATTACK = 0x100014u,
        PL1400_R0_CHARGE_RUN_START = 0x100015u,
        PL1400_R0_CHARGE_RUN = 0x100016u,
        PL1400_R0_AIR_LIGHT_ATTACK = 0x100017u,
        PL1400_R0_AIR_HEAVY_ATTACK = 0x100019u,
        PL1400_R0_CHARGE_AIR = 0x10001Au,
        PL1400_R0_DODGE = 0x10001Bu,
        PL1400_R0_TAUNT = 0x10001Cu,
        PL1400_R0_GUARD_WAIT = 0x10001Eu,
        PL1400_R0_WALL_COUNTER = 0x10001Du,
        PL1400_R0_GUARD_COUNTER = 0x10001Fu,
        PL1400_R0_GUARD_HIT = 0x100021u,
        PL1400_R0_GUARD_HIT_HEAVY = 0x100023u,
        PL1400_R0_INTERACT = 0x10002Bu,
        PL1400_R0_EXECUTION_HUMAN = 0x100066u,
        PL1400_R0_EXECUTION_MECH = 0x100067u,
    };

    int field_5400;
    int field_5404;
    int field_5408;
    int field_540C;
    int field_5410;
    float field_5414;
    float field_5418;
    float field_541C;
    int field_5420;
    int field_5424;
    int field_5428;
    int field_542C;
    int field_5430;
    int field_5434;
    int field_5438;
    int field_543C;
    int field_5440;
    int field_5444;
    int field_5448;
    int field_544C;
    short field_5450;
    int field_5454;
    int field_5458;
    int field_545C;
    int field_5460;
    int field_5464;
    int field_5468;
    int field_546C;
};

VALIDATE_SIZE(Pl1400, 0x5470);