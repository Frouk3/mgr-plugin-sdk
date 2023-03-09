#pragma once
#include "shared.h"

static struct StaFlags
{
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int STA_VR : 1;
    unsigned int b8 : 1;

    unsigned int b9 : 1;
    unsigned int STA_BATTLE_BGM : 1;
    unsigned int STA_IN_GAME_EVENT : 1;
    unsigned int STA_CAMERA_IGNORE_COLLIDE : 1;
    unsigned int STA_PAUSE : 1;
    unsigned int b14 : 1;
    unsigned int b15 : 1;
    unsigned int b16 : 1;
    
    unsigned int b17 : 1;
    unsigned int STA_BULLET_WITHOUT_COLLIDE : 1;
    unsigned int STA_CODEC : 1;
    unsigned int STA_PARKOUR_INVALID : 1;
    unsigned int STA_NINJARUN_INVALID : 1;
    unsigned int STA_ALWAYS_ZANGEKI : 1;
    unsigned int STA_NINJARUN : 1;
    unsigned int STA_VR_FIELD : 1;

    unsigned int STA_BLADEADDEFFECT : 1;
    unsigned int STA_QTE : 1;
    unsigned int STA_PLAYER_ATYPE_EFFECT_ON : 1;
    unsigned int STA_SOFT_EVENT : 1;
    unsigned int STA_SUSPEND : 1;
    unsigned int STA_DIE_DEMO : 1;
    unsigned int STA_EVENT : 1;
    unsigned int STA_SCENARIO : 1;

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
    unsigned int b47 : 1;
    
    unsigned int b48 : 1;
    unsigned int b49 : 1;
    unsigned int b50 : 1;
    unsigned int b51 : 1;
    unsigned int b52 : 1;
    unsigned int b53 : 1;
    unsigned int b54 : 1;
    unsigned int b55 : 1;

    unsigned int STA_COMB_CLEAR : 1;
    unsigned int b57 : 1;
    unsigned int STA_SOFT_EVENT_SKIP_OK : 1;
    unsigned int STA_PAUSE_NO_MOVE : 1;
    unsigned int STA_UI_START_FADE_IN_END : 1;
    unsigned int STA_OBJ_FADE_IN_WAIT : 1;
    unsigned int STA_OBJ_FADE_IN : 1;
    unsigned int b63 : 1;
} &g_StaFlags = *(StaFlags*)(shared::base + 0x17EA060);