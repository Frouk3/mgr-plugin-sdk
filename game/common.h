#pragma once
#include <Windows.h>
#include "shared.h"

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

inline void *eFree(void *block)
{
	return ((void *(__cdecl *)(void *))(shared::base + 0x9D4920))(block);
}

inline void *eAllocate(size_t size)
{
	auto operatorNew = *(void**)(shared::base + 0x177B794);
	if (!operatorNew)
		return nullptr;
	return ((void*(__cdecl *)(size_t))operatorNew)(size);
}

inline void eDeallocate(void *block)
{
	auto operatorDelete = *(void**)(shared::base + 0x177B790);
	if (operatorDelete)
		((void(__cdecl *)(void *))operatorDelete)(block);
}

inline bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);