#pragma once
#include "shared.h"
#include <math.h>

struct cVec4
{
  float x;
  float y;
  float z;
  float w;
  
  static inline void Normalize(cVec4 *v1, cVec4 *v2)
  { 
    ((void (__cdecl *)(cVec4 *, cVec4*))(shared::base + 0x9DF460))(v1, v2);
  }
  void operator=(const cVec4 &right)
  {
    this->x = right.x;
    this->y = right.y;
    this->z = right.z;
    this->w = right.w;
  }
  cVec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  };
  float Magnitude()
  {
    return sqrtf(powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2));
  }
  cVec4 &operator+=(const cVec4& rhs)
  {
      this->x += rhs.x;
      this->y += rhs.y;
      this->z += rhs.z;
      return *this;
  }
};

VALIDATE_SIZE(cVec4, 0x10);