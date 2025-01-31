#pragma once

#include <cmath>
#include <math.h>

enum RotateMatrixOrder
{
    ORDER_XYZ = 0x0,
    ORDER_XZY = 0x1,
    ORDER_YXZ = 0x2,
    ORDER_YZX = 0x3,
    ORDER_ZXY = 0x4,
    ORDER_ZYX = 0x5
};