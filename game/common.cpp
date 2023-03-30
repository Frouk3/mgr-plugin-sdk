#include "common.h"
#include "shared.h"

void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}

bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);