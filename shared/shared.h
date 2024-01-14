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
	inline bool key_state[512] = {}; // should be enough

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
	 * @brief Better key press check
	 * 
	 * It uses previous state and current state of keys to check it only once.
	 * RESET BEFORE KEY CHECK OR AFTER
	 * 
	 * @param[in] key - Virtual key
	 * @param[in] repeat - Should it check only once, default is true
	 * @param[in] ownerId - Used for owner
	 * 
	 * @return Returns bool according the key press
	 * */ 
	inline bool IsKeyPressed(int key, bool repeat = true, int ownerId = -1)
	{
		if (repeat)
			return (GetAsyncKeyState(key) & 0x8000) != 0;

		if (ownerId == -1)
			return false;

		bool keystat = (GetAsyncKeyState(key) & 0x8000) != 0;

		if (keystat != key_state[ownerId])
		{
			key_state[ownerId] = keystat;
			return key_state[ownerId];
		}

		if (keystat == key_state[ownerId])
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
inline ret ReturnCallVMTFunc(C self, Args... args)
{
	return ((ret (__thiscall *)(C, Args...))GetVMT(self, index))(self, args...);
}

template <size_t index, typename C, typename... Args>
inline void CallVMTFunc(C self, Args... args)
{
	((void (__thiscall *)(C, Args...))GetVMT(self, index))(self, args...);
}

template <typename ret, unsigned int address, typename C, typename... Args>
inline ret ReturnCallMethod(C self, Args... args)
{
	return ((ret (__thiscall *)(C, Args...))address)(self, args...);
}

template <unsigned int address, typename C, typename... Args>
inline void CallMethod(C self, Args... args)
{
	((void (__thiscall *)(C, Args...))address)(self, args...);
}

template<unsigned int address, typename... Args>
inline void CdeclCall(Args... args)
{
	((void (__cdecl*)(Args...))address)(args...);
}

template<typename ret, unsigned int address, typename... Args>
inline ret ReturnCdeclCall(Args... args)
{
	return ((ret (__cdecl *)(Args...))address)(args...);
}

template<typename ret, unsigned int address, typename... Args>
inline ret ReturnStdcall(Args... args)
{
	return ((ret (__stdcall *)(Args...))address)(args...);
}

template<unsigned int address, typename... Args>
inline void Stdcall(Args... args)
{
	((void (__stdcall *)(Args...))address)(args...);
}