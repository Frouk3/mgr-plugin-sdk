#pragma once

#include <cmath>
#include <math.h>
#include <shared.h>
#include <Hw.h>

class Random
{
private:
    unsigned int m_nSeed;
public:

    void reset()
    {
        ((void(__thiscall*)(Random*))(shared::base + 0x9DE290))(this);
    }

    void setSeed(unsigned int seed)
    {
        ((void(__thiscall*)(Random*, unsigned int))(shared::base + 0x9DBBD0))(this, seed);
    }

    short range(short min, short max)
    {
        return ((short(__thiscall*)(Random*, short, short))(shared::base + 0x9DE2D0))(this, min, max);
    }

    int range(int min, int max)
    {
        return ((int(__thiscall*)(Random*, int, int))(shared::base + 0x9DE2A0))(this, min, max);
    }

    float range(float min, float max)
    {
        return ((float(__thiscall*)(Random*, float, float))(shared::base + 0x9DE300))(this, min, max);
    }
};

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

    inline Random& m_Random = *(Random*)(shared::base + 0x19D0814);
}