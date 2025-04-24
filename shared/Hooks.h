#pragma once
#include <shared.h>
#include <Minhook/include/MinHook.h>

#pragma comment(lib, "libMinHook.x86.lib")

// For standard calling convention
#define CREATE_HOOK(startDisabled, target, ret, callconv, name, ...)	\
	struct sHooked_##name								\
	{													\
		static inline ret callconv hk##name(__VA_ARGS__);	\
		typedef ret(callconv *name##_t)(__VA_ARGS__);		\
		static inline name##_t o##name = NULL;				\
															\
		void Enable() { MH_EnableHook((LPVOID)(target)); }	\
		void Disable() { MH_DisableHook((LPVOID)(target)); }\
		sHooked_##name() { MH_CreateHook((LPVOID)(target), hk##name, (LPVOID*)&o##name); if (!startDisabled) Enable(); }  \
		~sHooked_##name() { Disable(); MH_RemoveHook((LPVOID)(target)); }						\
	} Hooked_##name;																							\
	ret callconv sHooked_##name::hk##name(__VA_ARGS__)

// Only for __thiscall convention, hooked function is __fastcall since `this` is moved into ecx register, where __fastcall can capture it
#define CREATE_THISCALL(startDisabled, target, ret, name, self, ...)	\
	struct sHooked_##name								\
	{													\
		static inline ret __fastcall hk##name(self pThis, void *, __VA_ARGS__);	\
		typedef ret(__thiscall *name##_t)(self pThis, __VA_ARGS__);		\
		static inline name##_t o##name = NULL;				\
															\
		void Enable() { MH_EnableHook((LPVOID)(target)); }	\
		void Disable() { MH_DisableHook((LPVOID)(target)); }\
		sHooked_##name() { MH_CreateHook((LPVOID)(target), hk##name, (LPVOID*)&o##name); if (!startDisabled) Enable(); }  \
		~sHooked_##name() { Disable(); MH_RemoveHook((LPVOID)(target)); }						\
	} Hooked_##name;																							\
	ret __fastcall sHooked_##name::hk##name(self pThis, void *, __VA_ARGS__)

class Hooks
{
private:
	struct MinHook_Static_Initialization { MinHook_Static_Initialization() { MH_Initialize(); } ~MinHook_Static_Initialization() { MH_Uninitialize(); }	 };
	static inline MinHook_Static_Initialization __MinHook; // Getting rid of this, so it won't popup for a user
public:
};