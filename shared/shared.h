#pragma once
#include <Windows.h>

namespace shared
{
	inline DWORD base = (DWORD)GetModuleHandleA(NULL);

	inline unsigned int random(unsigned int min, unsigned int max) noexcept
	{
		return min + (rand() % (max - min + 1));
	}

	inline bool IsKeyPressed(int key, bool repeat = false) noexcept
	{
		if (repeat)
			return (GetAsyncKeyState(key) & 0x8000) != 0;

		static bool first_press = true;

		if (GetAsyncKeyState(key) & 0x8000)
		{
			if (first_press)
			{
				first_press = false;
				return true;
			}
		}
		else
		{
			first_press = true;
			return false;
		}

		return false;
	}
}
