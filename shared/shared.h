#pragma once
#include <Windows.h>
#include <stdlib.h>

#define PI 3.14159265359f
#define DegreeToRadian(x) x * PI / 180
#define RadianToDegree(x) x * 180 / PI

namespace shared
{
	inline DWORD base = (DWORD)GetModuleHandleA(NULL);

	inline unsigned int random(unsigned int min, unsigned int max)
	{
		return min + (rand() % (max - min + 1));
	}

	inline bool IsKeyPressed(int key, bool repeat = true)
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

	inline int clamp(int x, int min, int max)
	{
		if (x < min)
			return min;
		else if (x > max)
			return max;
		
		return x;
	}

	inline float clamp(float x, float min, float max)
	{
		if (x < min)
			return min;
		else if (x > max)
			return max;

		return x;
	}
}
