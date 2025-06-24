#pragma once

#include <cmath>
#include <math.h>
#include <shared.h>
#include <Hw.h>

namespace cMath
{
    enum RotateMatrixOrder : int
    {
        ORDER_XYZ = 0x0,
        ORDER_XZY = 0x1,
        ORDER_YXZ = 0x2,
        ORDER_YZX = 0x3,
        ORDER_ZXY = 0x4,
        ORDER_ZYX = 0x5
    };


    inline float __cdecl normalizeAngle(float angle)
    {
        return ((float(__cdecl *)(float))(shared::base + 0x9DBA30))(angle);
    }

    inline void __cdecl rotateMatrix(D3DXMATRIX* matrix, const cVec4& rotation, RotateMatrixOrder order = ORDER_ZYX)
    {
        ((void(__cdecl*)(D3DXMATRIX*, const cVec4&, RotateMatrixOrder))(shared::base + 0x9DC1D0))(matrix, rotation, order);
    }

    inline void __cdecl matrixSetScale(D3DXMATRIX* matrix, const cVec4& scale)
    {
        ((void(__cdecl*)(D3DXMATRIX*, const cVec4&))(shared::base + 0x9DD140))(matrix, scale);
    }

    inline void __cdecl quatFromEulerAngles(cQuaternion& out, const cVec4& eulerAngles)
    {
        ((void(__cdecl*)(cQuaternion&, const cVec4&))(shared::base + 0x9DB590))(out, eulerAngles);
    }
}