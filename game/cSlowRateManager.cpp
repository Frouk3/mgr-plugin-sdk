#include "cSlowRateManager.h"
#include "../shared/shared.h"
#include <Windows.h>

void cSlowRateManager_SetSlowRate(int SlowRateType, float SlowRate) noexcept
{
	DWORD address = shared::base + 0x532020;
	((void(__cdecl*)(int, float))address)(SlowRateType, SlowRate);
}

cSlowRateManager* GetcSlowRateManager() noexcept
{
	DWORD address = shared::base + 0xA03960;
	return ((cSlowRateManager *(__stdcall*)())address)();
}

void cSlowRateManager::SetSlowRate(int SlowRateType, float SlowRate) noexcept
{
	DWORD address = shared::base + 0xA03A70;
	((void(__thiscall*)(cSlowRateManager*, int, float))address)(this, SlowRateType, SlowRate);
}

float cSlowRateManager::GetSlowRate(int SlowRateType) noexcept
{
	if (SlowRateType < 4)
		return this->m_fSlowRate[SlowRateType].m_fRate;
	else
		return 1.0f;
}

void cSlowRateManager::ResetSlowRate() noexcept
{
	DWORD address = shared::base + 0xA03B10;
	((void(__thiscall*)(cSlowRateManager*))address)(this);
}

void cSlowRateManager::Cleanup() noexcept
{
	DWORD address = shared::base + 0xA08740;
	((void(__thiscall*)(cSlowRateManager*))address)(this);
}

void cSlowRateManager_Reset() noexcept
{
	DWORD address = shared::base + 0x11EDC20;
	((void(__cdecl*)())address)();
}
