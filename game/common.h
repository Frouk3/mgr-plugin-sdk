#pragma once
#include <Windows.h>
#include "shared.h"

static void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}
// can't be used, only replaced
static void engine_printf(const char* fmt, ...)
{
    va_list va;
	va_start(va, fmt);
	((void(__cdecl*)(const char*, ...))(shared::base + 0x9D5650))(fmt, va);
	va_end(va);
}

static unsigned int stringhash32(const char* str, size_t length) // then later used for function that doesn't uses length
{
	return ((unsigned int (__cdecl *)(const char *, size_t))(shared::base + 0xA03D20))(str, length);
}

static unsigned int stringhash32(const char* str)
{
	return ((unsigned int (__cdecl *)(const char*))(shared::base + 0xA03EA0))(str);
}

static bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);