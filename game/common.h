#pragma once
#include <Windows.h>
#include "shared.h"
#include "Hw.h"

struct ContextInstance
{
	ContextInstance *m_inheritance;

	BOOL hasInheritance(ContextInstance *other)
	{
		return ((BOOL(__thiscall*)(ContextInstance*, ContextInstance*))(shared::base + 0x9D6D80))(this, other);
	}

	ContextInstance(ContextInstance &inheritance)
	{
		this->m_inheritance = &inheritance;
	}
};

// e prefix is indicated that it is used by the engine

inline void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}

inline void(*ePrintf)(const char* fmt, ...) = (void(*)(const char *, ...))(shared::base + 0x9D5650);

inline unsigned int stringhash32(const char* str, size_t length) // then later used for function that doesn't uses length
{
	return ((unsigned int (__cdecl *)(const char *, size_t))(shared::base + 0xA03D20))(str, length);
}

inline unsigned int stringhash32(const char* str)
{
	return ((unsigned int (__cdecl *)(const char*))(shared::base + 0xA03EA0))(str);
}

inline void * __cdecl eFree(void *block)
{
	return ((void *(__cdecl *)(void *))(shared::base + 0x9D4920))(block);
}

inline void *__cdecl AllocateMemory(size_t size)
{
	void *mem = Hw::cHeapGlobal::get()->allocate(size, 32u, 0, 0);
	if (mem)
		memset(mem, 0, size);
	return mem;
}

inline void __cdecl FreeMemory(void *block, int a2)
{
	((void(__cdecl*)(void*, int))(shared::base + 0x61D3D0))(block, a2); // most cases, deleted memory always has value of 0xEEEEEEEE
}

inline bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);