#pragma once

#include <cmath>
#include <math.h>
#include <shared.h>
#include <Hw.h>

namespace Hw
{
    inline float __cdecl RadAsinSafe(float x) { return MAKE_CALL(shared::base + 0x9DBAA0, float(__cdecl *)(float), x); }
    inline float __cdecl RadAdjust(float angle) { return MAKE_CALL(shared::base + 0x9DBA30, float(__cdecl *)(float), angle); }

    inline void __cdecl MtxAdd(Hw::cMtx& dst, const Hw::cMtx& lhs, const Hw::cMtx& rhs) { MAKE_CALL(shared::base + 0x9DBF80, void(__cdecl *)(Hw::cMtx&, const Hw::cMtx&, const Hw::cMtx&), dst, lhs, rhs); }
    inline void __cdecl MtxAddScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { MAKE_CALL(shared::base + 0x9DC020, void(__cdecl *)(Hw::cMtx&, const Hw::cMtx&, float), dst, src, scalar); }
    inline void __cdecl MtxSubScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { MAKE_CALL(shared::base + 0x9DC0B0, void(__cdecl *)(Hw::cMtx&, const Hw::cMtx&, float), dst, src, scalar); }
    inline void __cdecl MtxMulScalar(Hw::cMtx& dst, const Hw::cMtx& src, float scalar) { MAKE_CALL(shared::base + 0x9DC140, void(__cdecl *)(Hw::cMtx&, const Hw::cMtx&, float), dst, src, scalar); }
    inline void __cdecl MtxInitRotVec(Hw::cMtx& dst, const Hw::cVec3& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { MAKE_CALL(shared::base + 0x9DC1D0, void(__cdecl *)(Hw::cMtx&, const Hw::cVec4&, Hw::ROT_ORDER), dst, rot, order); }
    inline void __cdecl MtxInitRotVec(Hw::cMtx& dst, const Hw::cVec4& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { MAKE_CALL(shared::base + 0x9DC540, void(__cdecl *)(Hw::cMtx&, const Hw::cVec4&, Hw::ROT_ORDER), dst, rot, order); }
    inline void __cdecl MtxInitInvRotVec(Hw::cMtx& dst, const Hw::cVec3& rot, Hw::ROT_ORDER order = Hw::ROT_DEFAULT) { MAKE_CALL(shared::base + 0x9DC550, void(__cdecl *)(Hw::cMtx&, const Hw::cVec3&, Hw::ROT_ORDER), dst, rot, order); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec3& pos, const Hw::cVec3& nrm) { MAKE_CALL(shared::base + 0x9DC960, void(__cdecl *)(Hw::cMtx&, const Hw::cVec3&, const Hw::cVec3&), dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec4& pos, const Hw::cVec4& nrm) { MAKE_CALL(shared::base + 0x9DCA70, void(__cdecl *)(Hw::cMtx&, const Hw::cVec4&, const Hw::cVec4&), dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec4& pos, const Hw::cVec3& nrm) { MAKE_CALL(shared::base + 0x9DCA80, void(__cdecl *)(Hw::cMtx&, const Hw::cVec4&, const Hw::cVec3&), dst, pos, nrm); }
    inline void __cdecl MtxReflect(Hw::cMtx& dst, const Hw::cVec3& pos, const Hw::cVec4& nrm) { MAKE_CALL(shared::base + 0x9DCA90, void(__cdecl *)(Hw::cMtx&, const Hw::cVec3&, const Hw::cVec4&), dst, pos, nrm); }


    inline void __cdecl MtxOrtho(Hw::cMtx& dst, float left, float right, float bottom, float top, float z_near, float z_far) { MAKE_CALL(shared::base + 0x9DCBB0, void(__cdecl *)(Hw::cMtx&, float, float, float, float, float, float), dst, left, right, bottom, top, z_near, z_far); }
    inline void __cdecl MtxPerspective(Hw::cMtx& dst, float width, float height, float z_near, float z_far) { MAKE_CALL(shared::base + 0x9DCC50, void(__cdecl *)(Hw::cMtx&, float, float, float, float), dst, width, height, z_near, z_far); }
    inline void __cdecl MtxPerspectiveFovy(Hw::cMtx& dst, float fovy, float aspect, float z_near, float z_far) { MAKE_CALL(shared::base + 0x9DCCC0, void(__cdecl *)(Hw::cMtx&, float, float, float, float), dst, fovy, aspect, z_near, z_far); }
    inline void __cdecl MtxIdentity(Hw::cMtx& dst) { MAKE_CALL(shared::base + 0x9DCD80, void(__cdecl *)(Hw::cMtx&), dst); }
    inline void __cdecl MtxInitPos(Hw::cMtx& dst, const Hw::cVec3& pos) { MAKE_CALL(shared::base + 0x9DCDC0, void(__cdecl *)(Hw::cMtx&, const Hw::cVec3&), dst, pos); }
    inline void __cdecl MtxInitPos(Hw::cMtx& dst, float pos_x, float pos_y, float pos_z) { MAKE_CALL(shared::base + 0x9DCE10, void(__cdecl *)(Hw::cMtx&, float, float, float), dst, pos_x, pos_y, pos_z); }
    inline void __cdecl MtxInitScale(Hw::cMtx& dst, const Hw::cVec4& scale) { MAKE_CALL(shared::base + 0x9DD140, void(__cdecl *)(Hw::cMtx&, const Hw::cVec4&), dst, scale); }
    inline void __cdecl MtxLookAt(Hw::cMtx &dst, const Hw::cVec3& trans, const Hw::cVec3& target, const Hw::cVec3& rot) { MAKE_CALL(shared::base + 0x9E01A0, void(__cdecl *)(Hw::cMtx&, const Hw::cVec3&, const Hw::cVec3&, const Hw::cVec3&), dst, trans, target, rot); }
    inline void __cdecl VecHalfAngle(Hw::cVec4& out, const Hw::cVec4& inA, const Hw::cVec4& inB) { MAKE_CALL(shared::base + 0x09DEEC0, void(__cdecl *)(Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&), out, inA, inB); }
}