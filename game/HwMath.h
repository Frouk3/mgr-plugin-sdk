#pragma once

#include <cmath>
#include <math.h>
#include <shared.h>
#include <Hw.h>

namespace Hw
{
    inline float __cdecl RadAdjust(float angle) { return ((float(__cdecl *)(float))(shared::base + 0x9DBA30))(angle); }
    inline void __cdecl MtxInitRot(Hw::cMtx* matrix, const Hw::cVec4& rotation, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { ((void(__cdecl*)(Hw::cMtx*, const Hw::cVec4&, Hw::ROT_ORDER))(shared::base + 0x9DC1D0))(matrix, rotation, order); }
    inline void __cdecl MtxInitScale(Hw::cMtx* matrix, const Hw::cVec4& scale) { ((void(__cdecl*)(Hw::cMtx*, const Hw::cVec4&))(shared::base + 0x9DD140))(matrix, scale); }
    inline void __cdecl QuatFromRot(Hw::cQuat& out, const Hw::cVec4& eulerAngles) { ((void(__cdecl*)(Hw::cQuat&, const Hw::cVec4&))(shared::base + 0x9DB590))(out, eulerAngles); }
    inline void __cdecl VecNormalize(cVec4& out, const cVec4& in) { ((void(__cdecl *)(cVec4&, const cVec4&))(shared::base + 0x09DF460))(out, in); }
}