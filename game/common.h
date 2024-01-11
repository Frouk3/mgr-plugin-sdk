#pragma once
#include <Windows.h>
#include "shared.h"

inline void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}

inline void(*engine_printf)(const char* fmt, ...) = (void(*)(const char *, ...))(shared::base + 0x9D5650);

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

inline bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);