#pragma once

#include <Hw.h>

#define MAKE_JUMPINTOFUNC(address) do { __asm { __asm mov eax, shared::base  __asm add eax, address  __asm jmp eax  } } while(0)

namespace Hw
{
	namespace DebugDrawSystem
	{
		inline void __declspec(naked) __cdecl String(float x, float y, float fontsize, unsigned int color, const char* fmt, ...) { MAKE_JUMPINTOFUNC(0xB963B0); }
		inline void __declspec(naked) __cdecl String(float x, float y, const char* fmt, ...) { MAKE_JUMPINTOFUNC(0xB96550); }
		inline void __declspec(naked) __cdecl String(float x, float y, unsigned int color, int page, const char* format, ...) { MAKE_JUMPINTOFUNC(0xB96570); }
		inline void __declspec(naked) __cdecl String(float x, float y, float fontsize, unsigned int color, int page, const char* fmt, ...) { MAKE_JUMPINTOFUNC(0xB96580); }

		inline int __cdecl GetPageNo() { return ReturnCdeclCall<int, 0xB96420>(); }
		inline void __cdecl Circle(float x, float y, float r, unsigned int c) { CdeclCall<0xB95EB0, float, float, float, unsigned int>(x, y, r, c); }
		inline void __cdecl Line2D(float x0, float y0, float x1, float y1, unsigned int c) { CdeclCall<0xB95E40, float, float, float, float, unsigned int>(x0, y0, x1, y1, c); }
		inline void __cdecl Line3DArrow(const Hw::cVec4& min, const Hw::cVec4& max, unsigned int color, int a4) { CdeclCall<0xB95FA0, const Hw::cVec4&, const Hw::cVec4&, unsigned int, int>(min, max, color, a4); }
		inline void __cdecl Axes(const Hw::cMtx &mtx, float r, unsigned int f) { CdeclCall<0xB95FE0, const Hw::cMtx&, float, unsigned int>(mtx, r, f); }
		inline void __cdecl Axes(const Hw::cVec4& pos, float r, unsigned int f) { CdeclCall<0xB95FF0, const Hw::cVec4&, float, unsigned int>(pos, r, f); }
		inline void __cdecl Axes(const Hw::cVec3& pos, float r, unsigned int f) { CdeclCall<0xB96000, const Hw::cVec3&, float, unsigned int>(pos, r, f); }
		inline void __cdecl Box(const Hw::cMtx& matrix, const Hw::cVec4& extent, unsigned int color, int a5, int a6) { CdeclCall<0xB962E0, const Hw::cMtx&, const Hw::cVec4&, unsigned int, int, int>(matrix, extent, color, a5, a6); }
		inline void __cdecl Line3D(const Hw::cVec4& p0, const Hw::cVec4& p1, unsigned int color, int a4) { CdeclCall<0xB95F40, const Hw::cVec4&, const Hw::cVec4&, unsigned int, int>(p0, p1, color, a4); }
		inline void __cdecl AddDot(const Hw::cVec4& center, float fRadius, unsigned int color, float a4, float a5) { CdeclCall<0xB96100, const Hw::cVec4&, float, unsigned int, float, float>(center, fRadius, color, a4, a5); }
		inline void __cdecl AddCylinder(const Hw::cVec4& start, const Hw::cVec4& end, float width, unsigned int color, int a5, int a6) { CdeclCall<0xB961D0, const Hw::cVec4&, const Hw::cVec4&, float, unsigned int, int, int>(start, end, width, color, a5, a6); }
		inline void __cdecl Capsule(const Hw::cVec4& min, const Hw::cVec4& max, float width, unsigned int color, int a5, int a6) { CdeclCall<0xB96230, const Hw::cVec4&, const Hw::cVec4&, float, unsigned int, int, int>(min, max, width, color, a5, a6); }
		inline void __cdecl Capsule(const Hw::cVec3& min, const Hw::cVec3& max, float width, unsigned int color, int a5, int a6) { CdeclCall<0xB96220, const Hw::cVec3&, const Hw::cVec3&, float, unsigned int, int, int>(min, max, width, color, a5, a6); }
		inline void __cdecl Sphere(const Hw::cMtx& matrix, float width, unsigned int color, int a4, int a5) { CdeclCall<0xB96110, const Hw::cMtx&, float, unsigned int, int, int>(matrix, width, color, a4, a5); }
	}

	class cDebugLog;
}

class Hw::cDebugLog
{
public:
	static inline void (__cdecl* addMess)(const char* fmt, ...) = (void(__cdecl *)(const char*, ...))(shared::base + 0x9D5650);
	static inline void (__cdecl* addErr)(const char* fmt, ...) = (void(__cdecl *)(const char *, ...))(shared::base + 0x9D56A0);
};

#undef MAKE_JUMPINTOFUNC

struct DebugEventInfo
{
	int m_nSeTotal;
	int m_nSeInUse;
	int m_nSeFree;
	int m_nBgmTotal;
	int m_nBgmInUse;
	int m_nBgmFree;
	int m_nObjTotal;
	int m_nObjInUse;
	int m_nObjFree;
	int field_24;
	int field_28;
	int field_2C;
	Hw::cVec4 m_vecListenerPosition;
	Hw::cVec4 m_vecListenerDirection;
	int m_nSysEventTotal;
	int m_nSysEventInUse;
	int m_nSysEventFree;
	int m_nSysObjTotal;
	int m_nSysObjInUse;
	int m_nSysObjFree;
	int m_nCommandTotal;
	int m_nCommandInUse;
	int m_nCommandFree;
	int m_nTransferTotal;
	int m_nTransferInUse;
	int m_nTransferFree;
	float m_fSync;
	float m_fAsync;
	Hw::cHeap *m_pSysHeap;
};