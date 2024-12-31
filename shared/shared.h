#pragma once
#include <Windows.h>
#include <stdlib.h>

#pragma warning(disable : 26495)

#define PI 3.14159265359f
#define DegreeToRadian(x) (x * PI / 180)
#define RadianToDegree(x) (x * 180 / PI)
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)

class shared
{
private:
#ifdef SHARED_USE_EX_FUNCS
	// used for extended usage of key pressing(requires updating)
	static inline bool key_state_ex[256] = {};
	static inline bool prev_key_state[256] = {};
#else
	// used for simple key checking
	static inline bool key_state[256] = {};
#endif
public:
	static inline DWORD base = (DWORD)GetModuleHandleA(NULL);

	static inline unsigned int random(unsigned int min, unsigned int max)
	{
		return min + (rand() % (max - min + 1));
	}

	static inline int random(int min, int max)
	{
		return min + (rand() % (max - min + 1));
	}

	static inline float random(float min, float max)
	{
		return min + (max - min) * (rand() / float(RAND_MAX + 1));
	}
#ifdef SHARED_USE_EX_FUNCS
	
	static inline bool IsKeyPressed(int vKey, bool bRepeat = false)
	{
		if (bRepeat)
			return key_state_ex[vKey];

		return key_state_ex[vKey] && key_state_ex[vKey] != prev_key_state[vKey];
	}

	// should be passed after the update of everything(OnUpdateEvent.after for example)
	static inline void ExPressKeyUpdate()
	{
		memcpy(prev_key_state, key_state_ex, 256u);

		for (int i = 0; i < 256; i++)
			key_state_ex[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
	}

#else
	static inline bool IsKeyPressed(int vKey, bool bRepeat = true)
	{
		auto state = (GetAsyncKeyState(vKey) & 0x8000) != 0;

		if (bRepeat)
			return state;

		if (state != key_state[vKey])
		{
			key_state[vKey] = state;
			return state;
		}

		return false;
	}
#endif

	template <typename T>
	static inline T clamp(T x, T min, T max)
	{
		if (x < min)
			return min;
		else if (x > max)
			return max;

		return x;
	}
};

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
