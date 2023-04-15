#pragma once
#include "shared.h"

struct ARGB32
{
  float r;
  float g;
  float b;
  float a;
};

VALIDATE_SIZE(ARGB32, 0x10);