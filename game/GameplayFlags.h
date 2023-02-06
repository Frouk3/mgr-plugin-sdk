#pragma once
#include "shared.h"

// shared::base + 0x17EA094
struct GameplayFlags {
  unsigned int GAME_TGS_MODE : 1;
  unsigned int GAME_XY_ATTACK_OFF : 1;
  unsigned int GAME_TUTORIAL_FROM_STORY : 1;
  unsigned int b04 : 1;
  unsigned int b05 : 1;
  unsigned int GAME_DISABLE_ZANGEKI : 1;
  unsigned int GAME_PLAYER_VISOR_ENABLED : 1;
  unsigned int GAME_RUNNING_X_ATTACK_OFF : 1;

  unsigned int b09 : 1;
  unsigned int b10 : 1;
  unsigned int GAME_PLAYER_NO_LOCKON_BUTTON : 1;
  unsigned int b12 : 1;
  unsigned int GAME_EM0091_MANUPILATE : 1;
  unsigned int b14 : 1;
  unsigned int GAME_HP1_RAIDEN : 1;
  unsigned int GAME_DEPRESSSION_RAIDEN : 1;

  unsigned int GAME_SOLDIER_MONOLOGUE : 1;
  unsigned int GAME_KOGEKKO_PLAY : 1;
  unsigned int GAME_WEAPON_SELECT : 1;
  unsigned int GAME_SLIDER_NINJARUN_MODE : 1;
  unsigned int GAME_CODEC_SUBJECTIVE_POINT_VIEW : 1;
  unsigned int GAME_INZANGEKI_CAMDIR : 1;
  unsigned int GAME_CAMERA_INVERSE_X : 1;
  unsigned int GAME_CAMERA_INVERSE_Y : 1;

  unsigned int GAME_NO_EXP_ADD : 1;
  unsigned int GAME_ITEM_NO_DROP : 1;
  unsigned int GAME_PHASE_END_UI_DISP_OFF : 1;
  unsigned int GAME_RESULT_DISP_ON : 1;
  unsigned int GAME_BATTLECOLLISION_OFF : 1;
  unsigned int GAME_PLAYER_NO_DIVEKILL : 1;
  unsigned int GAME_PLAYER_NO_MOVE : 1;
  unsigned int GAME_PLAYER_NO_XA : 1;
} &g_GameplayFlags = *(GameplayFlags*)(shared::base + 0x17EA094);