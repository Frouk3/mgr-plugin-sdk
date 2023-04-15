#pragma once
#include "shared.h"

struct cVec4
{
  float x;
  float y;
  float z;
  float w;
  
  void Normalize(cVec4 *v1, cVec4 *v2);
  void operator=(cVec4 &right);
  cVec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
};

VALIDATE_SIZE(cVec4, 0x10);