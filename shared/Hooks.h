#pragma once
#include <shared.h>
#include <SafeHook.h>
#include <assert.h>

namespace Hooks
{
	class cBaseHook
	{
		SafeHook::Hook hook;
	public:
		cBaseHook() = default;
		cBaseHook(LPVOID target, LPVOID detour, LPVOID* original) : hook(target, detour, original) {}
		cBaseHook(LPVOID target, LPVOID detour, bool enable = true, LPVOID* original = nullptr) : hook(target, detour, enable, original) {}
		~cBaseHook() = default;

		void Enable() { hook.Enable(); }
		void Disable() { hook.Disable(); }
	};
}

#define CREATE_HOOK(disable, target, ret, calldecl, name, ...) namespace Hooks \
	{ \
		class hook##name : public cBaseHook \
		{ \
		public: \
			static inline ret calldecl name(__VA_ARGS__); \
			static inline ret(calldecl *original)(__VA_ARGS__) = nullptr; \
			hook##name() : cBaseHook((LPVOID)(target), name, !disable, (LPVOID*)&original) {} \
		}; \
	} \
	Hooks::hook##name Hook##name; \
	ret Hooks::hook##name::name(__VA_ARGS__)

#define CREATE_THISCALL(disable, target, ret, name, C, ...) namespace Hooks \
	{ \
		class hook##name : public cBaseHook \
		{ \
		public: \
			static inline ret __fastcall name(C pThis, void* edx, ##__VA_ARGS__); \
			static inline ret(__thiscall *original)(C pThis, ##__VA_ARGS__) = nullptr; \
			hook##name() : cBaseHook((LPVOID)(target), name, !disable, (LPVOID*)&original) {} \
		}; \
	} \
	Hooks::hook##name Hook##name; \
	ret Hooks::hook##name::name(C pThis, void* edx, ##__VA_ARGS__)