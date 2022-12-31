#include "common.h"
#include "shared.h"

void Core_PlaySound(const char* se, int unused) noexcept
{
	DWORD address = shared::base + 0xA5E050;
	((void(__cdecl*)(const char*, int))address)(se, unused);
}