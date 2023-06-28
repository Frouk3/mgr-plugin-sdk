#pragma once
#include <Windows.h>
#include <stdlib.h>

#define PI 3.14159265359f
#define DegreeToRadian(x) x * PI / 180
#define RadianToDegree(x) x * 180 / PI
// giving issues with size in Visual Studio Code(should not interact with code generation or compiling)
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)

namespace shared
{
	inline bool key_state[1024] = {};
	inline bool prevKey_state[1024] = {};

	inline DWORD base = (DWORD)GetModuleHandleA(NULL);

	inline unsigned int random(unsigned int min, unsigned int max)
	{
		return min + (rand() % (max - min + 1));
	}

	inline float random(float min, float max)
	{
		return min + (max - min) * (rand() / float(RAND_MAX + 1));
	}
	/**
	 * @param key Virtual key
	 * @param repeat If its repeatable, default is true
	*/
	inline bool IsKeyPressed(int key, bool repeat = true)
	{
		if (repeat)
			return (GetAsyncKeyState(key) & 0x8000) != 0;

		return (GetAsyncKeyState(key) & 1) != 0;
	}

	/**
	 * @brief Better key press check
	 * 
	 * It uses previous state and current state of keys to check it only once.
	 * 
	 * @param ownerId Can take id of key, but rather not used in bigger projects where ownerId is pushed as key
	 * @param key Virtual key
	 * @param repeat Should it check only once, default is true
	 * 
	 * @return Returns bool according the key press
	 * */ 
	inline bool IsKeyPressed(int ownerId, int key, bool repeat = true)
	{
		if (repeat)
			return IsKeyPressed(key, repeat);

		key_state[ownerId] = (GetAsyncKeyState(key) & 0x8000) != 0;

		if (prevKey_state[ownerId] != key_state[ownerId])
		{
			prevKey_state[ownerId] = key_state[ownerId];
			return prevKey_state[ownerId]; // or: return key_state[ownerId];
		}

		if (prevKey_state[ownerId] == key_state[ownerId])
			return false;

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

inline void** GetVMT(const void* self)
{
	return *(void***)(self);
}

inline void *GetVMT(const void* self, size_t index)
{
	return GetVMT(self)[index];
}

template <typename ret, size_t index, typename C, typename... Args>
ret ReturnCallVMTFunc(C self, Args... args)
{
	return ((ret (__thiscall *)(C, Args...))GetVMT(self, index))(self, args...);
}

template <size_t index, typename C, typename... Args>
void CallVMTFunc(C self, Args... args)
{
	((void (__thiscall *)(C, Args...))GetVMT(self, index))(self, args...);
}

template <typename ret, unsigned int address, typename C, typename... Args>
ret ReturnCallMethod(C self, Args... args)
{
	return ((ret (__thiscall *)(C, Args...))address)(self, args...);
}

template <unsigned int address, typename C, typename... Args>
void CallMethod(C self, Args... args)
{
	((void (__thiscall *)(C, Args...))address)(self, args...);
}