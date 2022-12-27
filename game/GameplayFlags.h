#pragma once
#include "../shared/shared.h"

// shared::base + 0x17EA094
enum GameplayFlags
{
  GAME_TGS_MODE = 0x1,
  GAME_PLAYER_XY_ATTACK_OFF = 0x2,
  GAME_TUTORIAL_FROM_STORY = 0x4,
  GAME_b3 = 0x8,
  GAME_b4 = 0x10,
  GAME_PLAYER_DISABLE_BLADE_MODE = 0x20,
  GAME_PLAYER_VISOR_ENABLED = 0x40,
  GAME_b7 = 0x80,
  GAME_b8 = 0x100,
  GAME_b9 = 0x200,
  GAME_PLAYER_NO_LOCKON_BUTTON = 0x400,
  GAME_b11 = 0x800,
  GAME_EM0091_MANIPULATE = 0x1000,
  GAME_b13 = 0x2000,
  GameHP1Raiden = 0x4000,
  GameDepresssionRaiden = 0x8000,
  GameSoldierMonologue = 0x10000,
  GameKogekkoPlay = 0x20000,
  GameWeaponSelect = 0x40000,
  GameSliderNinjarunMode = 0x80000,
  GameCodecSubjectivePointView = 0x100000,
  GameInzangekiCamdir = 0x200000,
  GAME_INVERSE_CAMERA_X = 0x400000,
  GAME_INVERSE_CAMERA_Y = 0x800000,
  GameNoExpAdd = 0x1000000,
  GameItemNoDrop = 0x2000000,
  GamePhaseEndUiDisplayOff = 0x4000000,
  GameResultDisplayOn = 0x8000000,
  GameBattlecollisionOff = 0x10000000,
  PlayerNoDiveKill = 0x20000000,
  PlayerNoMove = 0x40000000,
  PlayerNoXA = 0x80000000,
};

unsigned int &g_GameplayFlags = *(unsigned int*)(shared::base + 0x17EA094);