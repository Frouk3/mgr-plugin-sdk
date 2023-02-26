#include "common.h"
#include "shared.h"

void Core_PlaySound(const char* se, int unused) noexcept
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}