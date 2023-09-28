#pragma once
#include "shared.h"

struct ARGB32
{
  float r;
  float g;
  float b;
  float a;

  ARGB32(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f)
  {
	  this->r = r;
	  this->g = g;
	  this->b = b;
	  this->a = a;
  }
};

VALIDATE_SIZE(ARGB32, 0x10);