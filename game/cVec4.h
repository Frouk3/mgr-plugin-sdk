#pragma once

struct cVec4
{
  float x;
  float y;
  float z;
  float w;
  
  void Normalize(cVec4 &v1, cVec4 &v2) noexcept;
};
