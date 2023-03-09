#include "common.h"
#include "shared.h"

void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}

void printf(const char* fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	((void(__cdecl*)(const char*, ...))(shared::base + 0x9D5650))(fmt, va);
}

static bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);