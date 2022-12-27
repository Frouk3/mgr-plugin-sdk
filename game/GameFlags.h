#pragma once
#include "../shared/shared.h"

// shared::base + 0x17EA090
enum GameFlags
{
  QTEUiDisable = 0x1,
  MugenZangeki = 0x2,
  GameOSBootMode = 0x4,
  PlayerOneShotOff = 0x8,
  PlayerOneHand = 0x10,
  RipperModeOff = 0x20,
  NaviUiOn = 0x40,
  PlayerNoOverheat = 0x80,
  PlayerNoDie = 0x100,
  SystemMapAutoloadOff = 0x200,
  PlayerJumpOff = 0x400,
  PlayerDatsuOff = 0x800,
  PlayerGeckoTrail = 0x1000,
  PlayerGuardOff = 0x2000,
  NinjaRunOff = 0x4000,
  ZangekiOff = 0x8000,
  BPush = 0x10000,
  ActiveYPound = 0x20000,
  L1AttackOff = 0x40000,
  IgnoreParkourSliding = 0x80000,
  IgnoreParkourWall = 0x100000,
  IgnoreParkourDownwardCliff = 0x200000,
  IgnoreParkourLowover = 0x400000,
  PlayerAttackOff = 0x800000,
  WalkOnly = 0x1000000,
  MissileNinjaRunMode = 0x2000000,
  PlayerBattleMotionEnd = 0x4000000,
  PlayerBattleEnd = 0x8000000,
  AutoHPUp = 0x10000000,
  ZangekiMode = 0x20000000,
  RequireCommunication = 0x40000000,
  OldRaidenBody = 0x80000000,
};

unsigned int &g_GameFlags = *(unsigned int *)(shared::base + 0x17EA090);