#pragma once

#include <cmath>
#include <math.h>
#include <shared.h>
#include <Hw.h>

namespace Hw
{
    inline float __cdecl RadAsinSafe(float x) { return ReturnCdeclCall<float, 0x9DBAA0, float>(x); }
    inline float __cdecl RadAdjust(float angle) { return ReturnCdeclCall<float, 0x9DBA30, float>(angle); }

    inline void __cdecl MtxAdd(Hw::cMtx& dst, const Hw::cMtx& lhs, const Hw::cMtx& rhs) { CdeclCall<0x9DBF80, Hw::cMtx&, const Hw::cMtx&, const Hw::cMtx&>(dst, lhs, rhs); }
    inline void __cdecl MtxAddScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { CdeclCall<0x9DC020, Hw::cMtx&, const Hw::cMtx&, float>(dst, src, scalar); }
    inline void __cdecl MtxSubScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { CdeclCall<0x9DC0B0, Hw::cMtx&, const Hw::cMtx&, float>(dst, src, scalar); }
    inline void __cdecl MtxMulScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { CdeclCall<0x9DC140, Hw::cMtx&, const Hw::cMtx&, float>(dst, src, scalar); }
    inline void __cdecl MtxInitRotVec(Hw::cMtx& dst, const Hw::cVec3& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { CdeclCall<0x9DC1D0, Hw::cMtx&, const Hw::cVec4&, Hw::ROT_ORDER>(dst, rot, order); }
    inline void __cdecl MtxInitRotVec(Hw::cMtx& dst, const Hw::cVec4& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { CdeclCall<0x9DC540, Hw::cMtx&, const Hw::cVec4&, Hw::ROT_ORDER>(dst, rot, order); }
    inline void __cdecl MtxInitInvRotVec(Hw::cMtx& dst, const Hw::cVec3& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { CdeclCall<0x9DC550, Hw::cMtx&, const Hw::cVec3&, Hw::ROT_ORDER>(dst, rot, order); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec3& pos, const Hw::cVec3& nrm) { CdeclCall<0x9DC960, Hw::cMtx&, const Hw::cVec3&, const Hw::cVec3&>(dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec4& pos, const Hw::cVec4& nrm) { CdeclCall<0x9DCA70, Hw::cMtx&, const Hw::cVec4&, const Hw::cVec4&>(dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec4& pos, const Hw::cVec3& nrm) { CdeclCall<0x9DCA80, Hw::cMtx&, const Hw::cVec4&, const Hw::cVec3&>(dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec3& pos, const Hw::cVec4& nrm) { CdeclCall<0x9DCA90, Hw::cMtx&, const Hw::cVec3&, const Hw::cVec4&>(dst, pos, nrm); } // so many overloads :D
    // Rate must be between 0.0 and 1.0
    inline void __cdecl MtxLerp(Hw::cMtx& dst, const Hw::cMtx& lhs, const Hw::cMtx& rhs, _In_range_(0.0, 1.0) float rate) { CdeclCall<0x9DCAA0, Hw::cMtx&, const Hw::cMtx&, const Hw::cMtx&, float>(dst, lhs, rhs, rate); }
    inline void __cdecl MtxOrtho(Hw::cMtx& dst, float left, float right, float bottom, float top, float z_near, float z_far) { CdeclCall<0x9DCBB0, Hw::cMtx&, float, float, float, float, float, float>(dst, left, right, bottom, top, z_near, z_far); }
    inline void __cdecl MtxPerspective(Hw::cMtx& dst, float width, float height, float z_near, float z_far) { CdeclCall<0x9DCC50, Hw::cMtx&, float, float, float, float>(dst, width, height, z_near, z_far); }
    inline void __cdecl MtxPerspectiveFovy(Hw::cMtx& dst, float fovy, float aspect, float z_near, float z_far) { CdeclCall<0x9DCCC0, Hw::cMtx&, float, float, float, float>(dst, fovy, aspect, z_near, z_far); }
    inline void __cdecl MtxIdentity(Hw::cMtx& dst) { CdeclCall<0x9DCD80, Hw::cMtx&>(dst); }
    inline void __cdecl MtxInitPos(Hw::cMtx& dst, const Hw::cVec3& pos) { CdeclCall<0x9DCDC0, Hw::cMtx&, const Hw::cVec3&>(dst, pos); }
    inline void __cdecl MtxInitPos(Hw::cMtx& dst, float pos_x, float pos_y, float pos_z) { CdeclCall<0x9DCE10, Hw::cMtx&, float, float, float>(dst, pos_x, pos_y, pos_z); }
    inline void __cdecl MtxInitScale(Hw::cMtx& dst, const Hw::cVec4& scale) { ((void(__cdecl*)(Hw::cMtx&, const Hw::cVec4&))(shared::base + 0x9DD140))(dst, scale); }
    inline void __cdecl MtxLookAt(Hw::cMtx &dst, const Hw::cVec3& trans, const Hw::cVec3& target, const Hw::cVec3& rot) { ((void(__cdecl*)(Hw::cMtx&, const Hw::cVec3&, const Hw::cVec3&, const Hw::cVec3&))(shared::base + 0x9E01A0))(dst, trans, target, rot); }
    inline void __cdecl MtxLookAt(Hw::cMtx &dst, const Hw::cVec4& trans, const Hw::cVec4& target, const Hw::cVec4& rot) { ((void(__cdecl*)(Hw::cMtx&, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&))(shared::base + 0x9E05B0))(dst, trans, target, rot); }
    inline void __cdecl QuatFromRot(Hw::cQuat& out, const Hw::cVec4& eulerAngles) { ((void(__cdecl*)(Hw::cQuat&, const Hw::cVec4&))(shared::base + 0x9DB590))(out, eulerAngles); }
    inline void __cdecl VecNormalize(Hw::cVec4& out, const Hw::cVec4& in) { ((void(__cdecl *)(Hw::cVec4&, const Hw::cVec4&))(shared::base + 0x09DF460))(out, in); }
    inline void __cdecl VecHalfAngle(Hw::cVec4& out, const Hw::cVec4& inA, const Hw::cVec4& inB) { ((void(__cdecl *)(Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&))(shared::base + 0x09DEEC0))(out, inA, inB); }
}