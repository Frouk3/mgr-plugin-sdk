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
    unsigned int b7 : 1;
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
} &g_StaFlags = *(StaFlags*)(shared::base + 0x17EA060);