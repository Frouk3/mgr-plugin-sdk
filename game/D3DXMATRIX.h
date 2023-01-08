#pragma once
#include "D3DMATRIX.h"

typedef struct D3DXMATRIX : D3DMATRIX {
  float _ij;
} D3DXMATRIX, *LPD3DXMATRIX;