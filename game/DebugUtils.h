#pragma once

#include <Hw.h>

#define MAKE_JUMPINTOFUNC(address) __asm mov eax, shared::base __asm add eax, address __asm jmp eax

namespace DebugUtils
{
	inline void __declspec(naked) AddText(const cVec2 position, float fontsize, unsigned int color, const char* fmt, ...)
	{
		MAKE_JUMPINTOFUNC(0xB963B0);
	}

	inline void __declspec(naked) AddText(const cVec2 position, const char* fmt, ...)
	{
		MAKE_JUMPINTOFUNC(0xB96550);
	}

	inline void __declspec(naked) AddText(const cVec2 position, unsigned int color, int layer, const char* format, ...)
	{
		MAKE_JUMPINTOFUNC(0xB96570);
	}

	inline void __declspec(naked) AddText(const cVec2 position, float fontsize, unsigned int color, int layer, const char* fmt, ...)
	{
		MAKE_JUMPINTOFUNC(0xB96580);
	}

	inline int GetDebugLayer()
	{
		return ((int(__cdecl*)())(shared::base + 0xB96420))();
	}

	inline void AddCircle(const cVec2 center, float size, unsigned int color)
	{
		((void(__cdecl*)(const cVec2, float, unsigned int))(shared::base + 0xB95EB0))(center, size, color);
	}

	inline void AddLine(const cVec2 p1, const cVec2 p2, unsigned int color)
	{
		((void(__cdecl*)(const cVec2, const cVec2, unsigned int))(shared::base + 0xB95E40))(p1, p2, color);
	}

	inline void AddBox(const cVec4& min, const cVec4& max, unsigned int color, int a4)
	{
		((void(__cdecl*)(const cVec4&, const cVec4&, unsigned int, int))(shared::base + 0xB95FA0))(min, max, color, a4);
	}

	inline void AddLine3D(const cVec4& p1, const cVec4& p2, unsigned int color, int a4)
	{
		((void(__cdecl*)(const cVec4&, const cVec4&, unsigned int, int))(shared::base + 0xB95F40))(p1, p2, color, a4);
	}

	inline void AddSphere(const cVec4& center, float fRadius, unsigned int color, float a4, float a5)
	{
		((void(__cdecl*)(const cVec4&, float, unsigned int, float, float))(shared::base + 0xB96100))(center, fRadius, color, a4, a5);
	}
}

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
    cVec4 m_vecListenerPosition;
    cVec4 m_vecListenerDirection;
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