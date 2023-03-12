#pragma once
#include "shared.h"

static struct StpFlags
{
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int STP_KEY_INPUT : 1;

    unsigned int b9 : 1;
    unsigned int b10 : 1;
    unsigned int b11 : 1;
    unsigned int STP_TRG_DELAY_PL_CHK : 1;
    unsigned int b13 : 1;
    unsigned int STP_ENEMYSET : 1;
    unsigned int STP_SCENARIO : 1;
    unsigned int STP_EVENT_SKIP : 1;

    unsigned int STP_TRIGGER : 1;
    unsigned int STP_PL_CAM_KEY : 1;
    unsigned int STP_IK : 1;
    unsigned int STP_PL_ATTACK_KEY : 1;
    unsigned int STP_PL_MOVE_KEY : 1;
    unsigned int STP_PL_KEY : 1;
    unsigned int STP_SUBPL : 1;
    unsigned int STP_SHADOW : 1;

    unsigned int STP_FILTER : 1;
    unsigned int STP_UI : 1;
    unsigned int STP_SCR : 1;
    unsigned int STP_ESP : 1;
    unsigned int STP_ETCOBJ : 1;
    unsigned int STP_EM : 1;
    unsigned int STP_PL : 1;
    unsigned int STP_OBJ : 1;

    unsigned int b32 : 1;
    unsigned int b33 : 1;
    unsigned int b34 : 1;
    unsigned int b35 : 1;
    unsigned int b36 : 1;
    unsigned int b37 : 1;
    unsigned int b38 : 1;
    unsigned int b39 : 1;

    unsigned int b40 : 1;
    unsigned int b41 : 1;
    unsigned int b42 : 1;
    unsigned int b43 : 1;
    unsigned int b44 : 1;
    unsigned int b45 : 1;
    unsigned int b46 : 1;
    unsigned int STP_EM_BRAIN : 1;

    unsigned int b48 : 1;
    unsigned int b49 : 1;
    unsigned int b50 : 1;
    unsigned int b51 : 1;
    unsigned int b52 : 1;
    unsigned int b53 : 1;
    unsigned int b54 : 1;
    unsigned int b55 : 1;
    
    unsigned int b56 : 1;
    unsigned int b57 : 1;
    unsigned int b58 : 1;
    unsigned int b59 : 1;
    unsigned int b60 : 1;
    unsigned int b61 : 1;
    unsigned int b62 : 1;
    unsigned int STP_GAME_UPDATE : 1;
} &g_StpFlags = *(StpFlags *)(shared::base + 0x17EA070);